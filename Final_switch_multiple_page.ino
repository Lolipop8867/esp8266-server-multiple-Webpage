#include<ESP8266WiFi.h>
const char* ssid = "SSID";
const char* pass = "PASSWORD";
WiFiServer server(80);
String param = "";
String Access = "";
String value = "";
String state = "";
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
        state = param.substring(param.indexOf("=") + 1, param.indexOf("&")); //extract the value from the URI
        state.trim();
        Serial.println("param: " + param);
        Serial.println("Access: " + Access);
        Serial.println("value: " + value);
        Serial.println("state: " + state);
        /********************************html webpage************************************************/
        client.println("<!Doctype html>");
        client.println("<html>");
        if (Access == "login")
        {
          client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
          client.println("<link rel=\"icon\" href=\"data:,\">");
          client.println("<title>WELCOME</title>");
          client.println("<style> body{background-color:red;} h1{background-color:yellow;font-size:50px;} button{background-color:yellow;}</style>");
          client.println("</head>");
          client.println("<body>");
          client.println("<h1 align=center> WELCOME</h1>");
          client.println("<h2 align=center><b><u> click on the page button you wish to visit</u></b></h2>");
          client.println("<p align=center><a href=http:/page?value=1&><button><b>Page 1</b></button></a></p>");
          client.println("<p align=center><a href=http:/page?value=2&><button><b>Page 2</b></button></a></p>");
          client.println("<p align=center><a href=http:/page?value=3&><button><b>Page 3</b></button></a></p>");
          client.println("<p align=center><a href=http:/page?value=4&><button><b>Page 4</b></button></a></p>");
          client.println("<p align=center><a href=http:/page?value=5&><button><b>Page 5</b></button></a></p>");
          client.println("<p align=right><a href=http:/page?logout&><button><b>logout</b></button></a></p>");
        }
        else if ( Access == "page" && state == "1")
        {
          client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
          client.println("<link rel=\"icon\" href=\"data:,\">");
          client.println("<title>Page 1</title>");
          client.println("<style> body{background-color:red;} h1{background-color:yellow;font-size:75px;} button{background-color:yellow;}</style>");
          client.println("</head>");
          client.println("<body>");
          client.println("<h1 align=center> WELCOME <br> TO THE FIRST PAGE</h1>");
          client.println("<p align=right><a href=http:/login?><button>BACK</button></a></p>");
        }
        else if ( Access == "page" && state == "2")
        {
          client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
          client.println("<link rel=\"icon\" href=\"data:,\">");
          client.println("<title>Page 2</title>");
          client.println("<style> body{background-color:red;} h1{background-color:yellow;font-size:75px;} button{background-color:yellow;}</style>");
          client.println("</head>");
          client.println("<body>");
          client.println("<h1 align=center> WELCOME <br> TO THE SECOND PAGE</h1>");
          client.println("<p align=right><a href=http:/login?><button>BACK</button></a></p>");
        }
        else if ( Access == "page" && state == "3")
        {
          client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
          client.println("<link rel=\"icon\" href=\"data:,\">");
          client.println("<title>Page 3</title>");
          client.println("<style> body{background-color:red;} h1{background-color:yellow;font-size:75px;} button{background-color:yellow;}</style>");
          client.println("</head>");
          client.println("<body>");
          client.println("<h1 align=center> WELCOME <br> TO THE THIRD PAGE</h1>");
          client.println("<p align=right><a href=http:/login?><button>BACK</button></a></p>");
        }
        else if ( Access == "page" && state == "4")
        {
          client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
          client.println("<link rel=\"icon\" href=\"data:,\">");
          client.println("<title>Page 4</title>");
          client.println("<style> body{background-color:red;} h1{background-color:yellow;font-size:75px;} button{background-color:yellow;}</style>");
          client.println("</head>");
          client.println("<body>");
          client.println("<h1 align=center> WELCOME <br> TO THE FOURTH PAGE</h1>");
          client.println("<p align=right><a href=http:/login?><button>BACK</button></a></p>");
        }
        else if ( Access == "page" && state == "5")
        {
          client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
          client.println("<link rel=\"icon\" href=\"data:,\">");
          client.println("<title>Page 5</title>");
          client.println("<style> body{background-color:red;} h1{background-color:yellow;font-size:75px;} button{background-color:yellow;}</style>");
          client.println("</head>");
          client.println("<body>");
          client.println("<h1 align=center> WELCOME <br> TO THE FIFTH PAGE</h1>");
          client.println("<p align=right><a href=http:/login?><button>BACK</button></a></p>");
        }
        else if ( Access == "page" && value == "logout")
        {
          client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
          client.println("<link rel=\"icon\" href=\"data:,\">");
          client.println("<title>LOGOUT</title>");
          client.println("<style> body{background-color:black;} h1{background-color:yellow;font-size:100px;}</style>");
          client.println("</head>");
          client.println("<body>");
          client.println("<h1 align=center>THANK YOU</h1>");

        }

        else
        {
          client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
          client.println("<link rel=\"icon\" href=\"data:,\">");
          client.println("<title>ERROR</title>");
          client.println("<style> body{background-color:yellow;} h1{background-color:red;font-size:100px;} button{background-color:red;}</style>");
          client.println("</head>");
          client.println("<body>");
          client.println("<h1>ERROR!!!!!!!! USE PROPER URI TO ACCESS THE WEBPAGE</h1>");
        }
        client.println("</body>");
        client.println("</html>");
      break;

      }
    }
    client.flush();
    client.stop();
  }
}
