# HOSTING MUTIPLE WEB-PAGES USING THE ESP8266
This project explains how we can host multiple webpages using the powerfull ESP-8266 chip. Here we will be using the Arduino environment.
We will be starting a server on the ESP-8266 at port 80 and the RESTFULL API's will be used to switch from one webpage to another.

# NOTE:- 
Before doing this project having a prior knowledge of the following things is necessary
- How to make a web server with the ESP-8266.
- Basic concepts of the RESTful web services.
- What is a station and what is an access point. 

### NOTE: We will be using the HTTP GET requests for this project

# STEP 1: Start the web server
First we need to start the server on the ESP8266 and start listing to the clients from the port 80.
### NOTE: The server can be either a soft-AP server or the normal station server. This project can be configured to work in both the configuration.
# STEP 2: Check if the client is connected or not!
- Once the code is uploaded, then check for the WiFi Access point by the name SSID and type the password.
- Once you have successfully connected to the network, open your Web browser which in this case is the client, and type the IP   address as shown.
- If the ESP8266 is configured as the Station server, then use the WiFi.localIP() function to know the ip address.
- If the ESP8266 is configured as the soft-AP server, then by default 192.168.4.1 will the IP address.This IP address will be used to access the server. 
### NOTE: However in this project we will configure the ESP8266 as the soft-AP server.

# Step 3: Host Your First Web Page
- Now lets try to write a simple html code to display HELLO WORLD.
- Now once we connected to the same network and then we type the IP address of the server in the browser, then it should show a HELLO WORLD webpage.
### NOTE: however this is just for testing the server.

# Step 4: Managing the GET REQUESTS
- As shown in the step 3, to access the webpage, we just type the IP address of the server on the browser. Now lets do something very interesting.
- We are now going to access the various web pages using the GET requests.
- In this example the GET request is of the type : http:/192.168.4.1/first?first&
- If we type the above URI in the browser, then we see a welcome webpage but if we type any other URI it will show a error webpage.

### NOTE:Refer the start_server.ino for the detailed view of the code

# Step 5: Final Step: Switching From One Web Page to Another Webpage
- To first visit the Login page use the following URI: http:/192.168.4.1/login?
- Then the following URI is used to switch from one page to another: http:/192.168.4.1/page?value=pageNumber&.
### Example :
- http:/192.168.4.1/page?value=1& will go to the first page
- http:/192.168.4.1/page?value=5& will go to the last page
- http:/192.168.4.1/page?logout& will display the Thank you page
### NOTE: Refer to the Final_switch_multiple_page.ino for the detailed view of the code:




