#include <SD.h>                      // Sd kütüphanesi projeye dahil edildi
#define SD_ChipSelectPin 10  //Sd Kart Adaptöründeki cs pininin arduino'ya baglandigi pin 
#include <TMRpcm.h>         //Kullanılan ana kütüphane  
#include <SPI.h>            //Spi kütüphanesi projeye dahil edildi.

//Buton pinleri tanımlandı.
#define buton1 5
#define buton2 6
#define buton3 7

//tmrpcm objesi oluşturuldu.
TMRpcm tmrpcm;   


void setup(){
//Buton pinlerinin giriş pini olduğu belirtildi.  
  pinMode(buton1, INPUT);
  pinMode(buton2, INPUT);
  pinMode(buton3, INPUT);

  tmrpcm.speakerPin = 9; //Hoparlörün bağlandığı pin.

  //Serial haberleşme başlatıldı.
  Serial.begin(9600);
  

  if (!SD.begin(SD_ChipSelectPin)) {  // Sd kart adaptörü çalışmıyorsa
    Serial.println("SD karta bağlantı başarısız.");  
    return;   // Başka bir işlem yapma.

  }
  else{   
    Serial.println("SD karta bağlanıldı.");   
  }
  tmrpcm.play("ncs.wav"); //Çalınmak istenen şarkınan adı.
  tmrpcm.setVolume(1); //Ses miktarı ayarlandı.
}


void loop(){  
    if (digitalRead(buton1)==HIGH){ //Buton1'e basıldıysa
    tmrpcm.volume(1);  //Sesi arttır.
    delay(500); //Fazladan veri gönderilmemesi için gecikme.
  }
    if (digitalRead(buton2)==HIGH){ //Buton2'e basıldıysa
    tmrpcm.volume(0); //Sesi azalt.
    delay(500); //Fazladan veri gönderilmemesi için gecikme.
  }
    if (digitalRead(buton3)==HIGH){ //Buton 3'e basıldıysa
    if(tmrpcm.isPlaying()){  //Şarkı çalıyor mu kontrol et 
      tmrpcm.pause(); //Çalıyorsa durdur. Çalmıyorsa devam ettir.
      }
    delay(500); //Fazladan veri gönderilmemesi için gecikme.
  }

}
