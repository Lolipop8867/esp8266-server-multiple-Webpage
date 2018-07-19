#include<ESP8266WiFi.h>
const char* ssid = "SSID";
const char* pass = "PASSWORD";
WiFiServer server(80);
String param = "";
String Access = "";
String value = "";
void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, pass);
  delay(100);
  server.begin();

  // put your setup code here, to run once:

}

void loop() {
  WiFiClient client = server.available();   // Listen for incoming clients
  if (client)
  {
    Serial.println("NEW CLIENT");
    client.print("GET/HTTP/1.1 200 OK\r\n Host:192.168.4.1\r\n Connection: close\r\n\r\n");// If a new client connects,
    while (client.connected()) {
      // loop while the client's connected
      if (client.available())
      {
        param = client.readStringUntil('\n');                         // check for the incoming client requests
        Serial.println(param);
        param.trim();
        Access = param.substring(param.indexOf("/") + 1, param.indexOf("?")); //extract the path from the URI
        Access.trim();
        value = param.substring(param.indexOf("?") + 1, param.indexOf("&")); //extract the value from the URI
        value.trim();
        Serial.println("param: " + param);
        Serial.println("Access: " + Access);
        Serial.println("value: " + value);
        /********************************html webpage************************************************/
        client.println("<!Doctype html>");
        client.println("<html>");
        if (Access == "first" && value == "true")
        {
          client.println("<head>");
          client.println("<title>WELCOME</title>");
          client.println("<style> body{background-color:red;} h1{background-color:yellow;font-size:100px;}</style>");
          client.println("</head>");
          client.println("<body>");
          client.println("<h1 align=center> WELCOME</h1>");
          client.println("<h2><p>What are the differnt HTTP methods used in the Rest architecture:</p></h2>");
          client.println("<h2><ul><li>GET</li><li>POST</li><li>DELETE</li><li>PUT</li></ul></h2>");

        }
        else
        {
          client.println("<head>");
          client.println("<title>ERROR</title>");
          client.println("<style> body{background-color:red;} h1{background-color:yellow;font-size:100px;}</style>");
          client.println("</head>");
          client.println("<body>");
          client.println("<h1 align=center>ERROR</h1>");

        }

        client.println("</body>");
        client.println("</html>");

      }
      break;
    }
    client.flush();
  }
  client.stop();
}
