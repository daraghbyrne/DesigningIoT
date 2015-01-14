byte mac[6];
char macstr[18];

void setup() {

  // Turn on the WiFi and connect to the network
  WiFi.on();
  WiFi.connect();

  // Set up a cloud variable to hold the mac address
  Spark.variable("mac", macstr, STRING);

  // Retrieve the network mac address
  WiFi.macAddress(mac);

  // create a formatted string with the MAC Address
  // and assign it to the cloud variable
  snprintf(macstr, 18, "%02x:%02x:%02x:%02x:%02x:%02x", mac[5], mac[4], mac[3], mac[2],mac[1], mac[0]);

}

void loop() {

  // Retrieve the network mac address
  WiFi.macAddress(mac);

  // create a formatted string with the MAC Address
  // and assign it to the cloud variable
  snprintf(macstr, 18, "%02x:%02x:%02x:%02x:%02x:%02x", mac[5], mac[4], mac[3], mac[2],mac[1], mac[0]);

  // delay for 1 second
  delay(1000);
}
