// 2021 Murat Gungor
// Ref: https://gist.github.com/outofmbufs/d6ced37b49a484c495f0
//      https://github.com/Siytek/AnotherIFTTTWebhook

#include <WiFiNINA.h>
WiFiClient IFTTTclient; 

#define IFTTT_URL "maker.ifttt.com"
#define IFTTT_PORT 80

void callWebhook(String eventName, String webHookKey, String value1) {

    //Connect to the Maker event server
    IFTTTclient.connect(IFTTT_URL, IFTTT_PORT);

    //JSON Data
    String jsonPayload = "";
    // jsonPayload.concat("{\"temperature\":\"");
    // jsonPayload.concat(value1);
    // jsonPayload.concat("\",\"humidity\":\"");
    // jsonPayload.concat(value2);
    // jsonPayload.concat("\"}");
    jsonPayload.concat("{\"direction\":\"");
    jsonPayload.concat(value1);
    jsonPayload.concat("\"}");

    //Construct the POST request    
    String requestInfo = "";
    requestInfo.concat("POST /trigger/");
    requestInfo.concat(eventName);
    requestInfo.concat("/json/with/key/");
    requestInfo.concat(webHookKey);
    requestInfo.concat(" HTTP/1.1\r\n");
    requestInfo.concat("Host: ");
    requestInfo.concat(IFTTT_URL);
    requestInfo.concat("\r\n");
    requestInfo.concat("Content-Type: application/json\r\n");
    requestInfo.concat("Content-Length: ");
    requestInfo.concat(jsonPayload.length());
    requestInfo.concat("\r\n");
    requestInfo.concat("\r\n");;
    requestInfo.concat(jsonPayload);

    // finally we are ready to send the POST to the server!
    IFTTTclient.print(requestInfo);
    IFTTTclient.stop();    

    Serial.println("requestURL");
    Serial.println(requestInfo);
}
/*
SAMPLE POST DATA

POST /trigger/email_me/with/key/dj82Kc25Hje285vHAOmnCx HTTP/1.1
Host: maker.ifttt.com
Content-Type: application/json
Content-Length: 70

{"value1":"Another IFTTT","value2":"MKR WIFI 1010","value3":"Webhook"}


*/