# Mario-Gaming-Machine-with-PIC18
> 題目名稱 : **鼓動吧~魔方!**
## 動機

## 設備
    1. 4 * 4 * 4 LED 魔方 * 1
    2. PIC18F4520 * 3
    3. 陶瓷震動感應器 * 1
    4. 敲擊傳感器 * 2
    5. 自製環保鼓 * 1
    6. 自製環保鑼 * 2
## 功能
你必須觀察**魔方**上，三個通道的燈光變化，並且在不同的時機點打擊鼓面或者對鑼進行敲打，並會根據**遊戲狀態**來會顯示fast, perfect, slow。
為了讓音樂的內容更加豐富，如同8bit的音樂製作一樣，我們額外也使用了多個喇叭，分別呈現主旋律與其和聲，演奏出更豐富的音樂。
![](https://i.imgur.com/xtnqyck.jpg)

## 原理說明:
* **陶瓷震動感測器:** 
我們使用壓感式陶瓷震動感測器，當有壓力時才會有不同程度的電流流通。為此，我們使用一個pic晶片來運行adc，來讀取鼓上的陶瓷震動感測器之數值，只有大於threshold的數值能被判定為有效地敲擊。
* **敲擊傳感器:** 
上方有線圈，當受到晃動時，會產生磁場變化，藉此來感測我們鑼片的晃動。
* **魔方:** 
考量到PIC上腳位的數量，我們使用類似點矩陣模組，由16 + 4 個Pin來控制，從下而上快速的Scan每一層，透過視覺暫留來讓我們產生cube是持續亮著的錯覺。
## 初步系統架構:
**1.** **Main model(PIC 1)** : 使用UART負責接受遊戲選擇模式，
運行數個timer，分別是
* **TMR0 :**
因為我們使用100beats的音樂，所以TMR0每0.15秒會觸發一次，然後根據**節拍表**來決定需要幾個delay，並且讀取**遊戲節擊打表**來判斷是否應為敲打的節奏位置。
* **TMR1 :** 
每0.15秒變化一次遊戲狀態，為fast state、perfect state、slow state。
* **TMR2 :**
為了讓魔方只亮特定的LED，我們藉由TMR2來產生666Hz的Scanning rate。

另外使用INT0~INT2，當敲擊鼓面跟鑼片時，會觸發interrupt trigger，判斷現在現在的遊戲狀態為何者，並且閃爍特定的LED來讓使用者知道自己的敲擊是否準確。

**2.** **ADC + Music player model(PIC 2)** : 
* **ADC :** 當收到從main model輸入訊號來啟動ADC，並進行Sample rate為100Hz的取樣，如果超過我們所設定的threshold，就將output設為1，用來觸發main model的INT2。
* **Music player :** 當要變換不同的音符時，Main model(PIC 1)會將特定的output設為1，用來觸發 Music player(PIC 2)的INT0，藉此來確保不同PIC上音樂撥放的同步。

**3.** **Music player model(PIC 3)** : 如同PIC 2的music player。

## 創意特色描述

致敬經典遊戲瑪利歐兄弟，利用晶片唱出經典馬力歐組題曲，搭配LED CUBE的視覺效果，。

## 系統完整架構圖、流程圖、電路圖、設計圖
![](https://i.imgur.com/3PJxxPI.png)
![](https://i.imgur.com/8hJRFDe.jpg)

## 系統開發工具、材料及技術
PIC18F4520 * 3:Master-Slave 技術之應用及實作。
陶瓷振盪感測器:擠壓陶瓷面導致電流導通。
 
   敲擊傳感器：透過晃動線圈來讓磁場產生變，並且產生應電流來回傳。
 
   蜂鳴器、喇叭：主旋律及和弦的播放。
 
   LED燈組：以類似點矩陣的方式操縱Pin，用以解決PIC的腳位數不足的問題。
 

