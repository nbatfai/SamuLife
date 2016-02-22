# SamuLife
[Samu](http://arxiv.org/abs/1511.02889) (Nahshon) has learnt the rules of Conway's Game of Life. This is 
an example of the paper entitled "Samu in his prenatal development".

This project uses the same COP-based Q-learning engine as Samu ([Nahshon](https://github.com/nbatfai/nahshon)) to predict the next sentences of a conversation. 

## Experiments
* #1: [https://youtu.be/p936TRxfC2I](https://youtu.be/p936TRxfC2I) It works very well, but its algorithm is unreasonable 
(the interpretation of the rewarding is unreasonable). 
* #2, v0.0.1-buggyQL: [https://youtu.be/WNrf9OhSbPQ](https://youtu.be/WNrf9OhSbPQ) 
The behaviour and the algorithm of this is the same as the previous one.
* #3, v0.0.2-manySamus-withoutNN-toYouTube: (so many little Samus, without neural network architecture, it uses a simple lookup table) 
[https://youtu.be/BnNVM8XNDSA](https://youtu.be/BnNVM8XNDSA) 
This algorithm has already been reasonable and it has worked very well.
* #4, v0.0.3-manySamus-withNN-toYouTube: [https://youtu.be/b60m__3I-UM](https://youtu.be/b60m__3I-UM) 
If this algorithm is the same as the previous (reasonable but now with neural networks to approximate the Q values) then it has 
not yet worked very well. But with a modified perception, this algorithm has also been reasonable and it has worked very well too.
* #5, v0.0.4-predicting-the-present-eliminated: It is important to note that in the previous version the COP-based Q-learning 
has become trivial because after a short starting period it chooses the Q-action 
that was passed in as the actual cell state argument. It means that the agent 
does not predict the future but the present. This version has already been 
improved. It really predicts the future that can be seen well in the video at 
https://youtu.be/j6bus5efESU
* #6, v0.0.5-buggy+rewardtable:

## Usage

```
git clone https://github.com/nbatfai/SamuLife.git
cd SamuLife/
~/Qt/5.5/gcc_64/bin/qmake SamuLife.pro
make
./SamuLife
```

## Experiments with this project


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

![slexp3](https://cloud.githubusercontent.com/assets/3148120/12130724/2d36e82e-b40d-11e5-9412-acb9bff4e932.png)

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

![slexp4](https://cloud.githubusercontent.com/assets/3148120/12130890/88a380e0-b40e-11e5-9459-7d204669baa0.png)


### v0.0.4-predicting-the-present-eliminated

It is important to note that in the previous version the COP-based Q-learning 
has become trivial because after a short starting period it chooses the Q-action 
that was passed in as the actual cell state argument. It means that the agent 
does not predict the future but the present. This version has already been 
improved. It really predicts the future that can be seen well in the video at 
https://youtu.be/j6bus5efESU

```
git clone https://github.com/nbatfai/SamuLife.git
cd SamuLife/
git checkout v0.0.4-predicting-the-present-eliminated
~/Qt/5.5/gcc_64/bin/qmake SamuLife.pro
make
./SamuLife
```


[https://youtu.be/j6bus5efESU](https://youtu.be/j6bus5efESU)

![screenshot from 2016-02-04 11-10-17](https://cloud.githubusercontent.com/assets/3148120/12811945/f38a0d4c-cb2f-11e5-815e-7a1212f62aff.png)

## Other experiments

Samu (Nahshon)
http://arxiv.org/abs/1511.02889, 
https://github.com/nbatfai/nahshon

---

SamuMovie
https://github.com/nbatfai/SamuMovie, 
https://youtu.be/XOPORbI1hz4

SamuStroop
https://github.com/nbatfai/SamuStroop, 
https://youtu.be/6elIla_bIrw, 
https://youtu.be/VujHHeYuzIk

SamuBrain
https://github.com/nbatfai/SamuBrain

SamuCopy
https://github.com/nbatfai/SamuCopy

---

SamuTicker
https://github.com/nbatfai/SamuTicker

SamuVocab
https://github.com/nbatfai/SamuVocab