# SamuLife
Samu (Nahshon) has learnt the rules of Conway's Game of Life. This is 
an example of the paper entitled "Samu in his prenatal development".

This project uses the same COP-based Q-learning engine as [Samu(Nahshon)](https://github.com/nbatfai/nahshon) to predict the next sentences of a conversation. 

## Demo
* #1: [https://youtu.be/p936TRxfC2I](https://youtu.be/p936TRxfC2I) It works very well, but its algorithm is unreasonable. 
* #2, v0.0.1-buggyQL: [https://youtu.be/WNrf9OhSbPQ](https://youtu.be/WNrf9OhSbPQ) 
The behaviour and the algorithm of this is the same as the previous one.
* #3, v0.0.2-manySamus-withoutNN-toYouTube: (so many little Samus, without neural network architecture) [http](http) 
This algorithm has already been reasonable and it has worked very well.
* #3, v0.0.3-manySamus-withNN: [http](http) 
This algorithm is the same as the previous (reasonable) one but it uses neural networks to approximate the Q values 
and it has not yet worked very well.
* #4, v0.0.4-buggy+table:

## Usage

### v0.0.1-buggyQL
```
git clone https://github.com/nbatfai/SamuLife.git
cd SamuLife/
git checkout v0.0.1-buggyQL
~/Qt/5.5/gcc_64/bin/qmake SamuLife.pro
make
./SamuLife
```
![samulife](https://cloud.githubusercontent.com/assets/3148120/12007817/7252e9c0-ac16-11e5-9b7a-faa747d93929.png)

### v0.0.2-manySamus-withoutNN

```
git clone https://github.com/nbatfai/SamuLife.git
cd SamuLife/
git checkout v0.0.2-manySamus-withoutNN
~/Qt/5.5/gcc_64/bin/qmake SamuLife.pro
make
./SamuLife
```
