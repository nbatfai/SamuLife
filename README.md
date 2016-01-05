# SamuLife
[Samu](http://arxiv.org/abs/1511.02889) (Nahshon) has learnt the rules of Conway's Game of Life. This is 
an example of the paper entitled "Samu in his prenatal development".

This project uses the same COP-based Q-learning engine as [Samu(Nahshon)](https://github.com/nbatfai/nahshon) to predict the next sentences of a conversation. 

## Demo
* #1: [https://youtu.be/p936TRxfC2I](https://youtu.be/p936TRxfC2I) It works very well, but its algorithm is unreasonable 
(the interpretation of the rewarding is unreasonable). 

* #2, v0.0.1-buggyQL: [https://youtu.be/WNrf9OhSbPQ](https://youtu.be/WNrf9OhSbPQ) 
The behaviour and the algorithm of this is the same as the previous one.

* #3, v0.0.2-manySamus-withoutNN-toYouTube: (so many little Samus, without neural network architecture, it uses simple lookup table) 
[https://youtu.be/BnNVM8XNDSA](https://youtu.be/BnNVM8XNDSA) 
This algorithm has already been reasonable and it has worked very well.

* #4, v0.0.3-manySamus-withNN-toYouTube: [https://youtu.be/b60m__3I-UM](https://youtu.be/b60m__3I-UM) 
If this algorithm is the same as the previous (reasonable and with neural networks to approximate the Q values) then it has 
not yet worked very well. But with a modified perception, this algorithm has also been reasonable and it has worked very well too.

* #5, v0.0.4-buggy+rewardtable:

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
[https://youtu.be/WNrf9OhSbPQ](https://youtu.be/WNrf9OhSbPQ)

![samulife](https://cloud.githubusercontent.com/assets/3148120/12007817/7252e9c0-ac16-11e5-9b7a-faa747d93929.png)

### v0.0.2-manySamus-withoutNN-toYouTube

```
git clone https://github.com/nbatfai/SamuLife.git
cd SamuLife/
git checkout v0.0.2-manySamus-withoutNN-toYouTube
~/Qt/5.5/gcc_64/bin/qmake SamuLife.pro
make
./SamuLife
```
[https://youtu.be/BnNVM8XNDSA](https://youtu.be/BnNVM8XNDSA)

### v0.0.3-manySamus-withNN-toYouTube

```
git clone https://github.com/nbatfai/SamuLife.git
cd SamuLife/
git checkout v0.0.3-manySamus-withNN-toYouTube
~/Qt/5.5/gcc_64/bin/qmake SamuLife.pro
make
./SamuLife
```
[https://youtu.be/b60m__3I-UM](https://youtu.be/b60m__3I-UM)

