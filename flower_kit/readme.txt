    1 USB 드라이브 설치
    
    CH341SER/SETUP.EXE
    

    2 라이브러리 설치
    LiquidCrystal_I2C-master.zip 압축풀기
    LiquidCrystal_I2C-master 폴더를 복사
    
    C:\Users\{{yourid}}\Documents\Arduino\libraries\LiquidCrystal_I2C-master

완성된 화분 키트 영상

    https://m.eduino.kr/product/detail.html?product_no=437

    https://youtu.be/xbuE3Wsoups
    
    
         LCD Address scan

         #include <Wire.h>

        void setup()
        {
        Wire.begin();

        Serial.begin(9600);
        while (!Serial); // Leonardo: wait for serial monitor
        Serial.println("\nI2C Scanner");
        }

        void loop()
        {
        byte error, address;
        int nDevices;

        Serial.println("Scanning…");

        nDevices = 0;
        for(address = 1; address < 127; address++ )
        {
        // The i2c_scanner uses the return value of
        // the Write.endTransmisstion to see if
        // a device did acknowledge to the address.
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0)
        {
        Serial.print("I2C device found at address 0x");
        if (address<16)
        Serial.print("0");
        Serial.print(address,HEX);
        Serial.println(" !");

        nDevices++;
        }
        else if (error==4)
        {
        Serial.print("Unknown error at address 0x");
        if (address<16)
        Serial.print("0");
        Serial.println(address,HEX);
        }
        }
        if (nDevices == 0)
        Serial.println("No I2C devices found\n");
        else
        Serial.println("done");

        delay(5000); // wait 5 seconds for next scan
        }


