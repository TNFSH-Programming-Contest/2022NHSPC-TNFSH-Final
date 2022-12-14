# 復活節彩蛋

\begin{figure}[h]
\centering
\includegraphics[width=12cm]{img.jpg}
\caption{女高中生報導員：小決、報瀨、日向、結月四人。出自動畫《比宇宙更遠的地方》}
\end{figure}

經過困難重重的挑戰和各種因緣際會，小決、報瀨、日向、結月四人，終於跟著民間探險隊「南極挑戰」，踏上了比宇宙更遠的地方—南極。\
在景色一成不變、感受不到時間流逝的南極，節日是非常被重視的。今天是復活節，南極挑戰的大家給小決、報瀨、日向、結月四人準備了找彩蛋的遊戲。

地圖上標示了 $n$ 個冰屋，其中一個藏著一籃彩蛋。除了藏著彩蛋的冰屋，其餘都標示了一個箭頭，指向另一個冰屋。\
並且從任一冰屋開始，不斷的沿著箭頭走向下一個冰屋，終點一定是藏著彩蛋的冰屋。

然而淘氣的廚師長弓子為了捉弄四人，在把地圖交給他們前，把箭頭的方向都塗掉了。\
她還壞心地在地圖的背面寫下了 $q$ 個線索，不保證其真假。
每個線索以 $x,~y,~z$ 的格式來表示，代表從 $x$ 沿箭頭走向終點、和從 $y$ 沿箭頭走向終點，會經過的共同的冰屋中，離終點最遠的是 $z$。

拿到了地圖的四人，看著 $q$ 個線索不知所措。
經過片刻討論，她們決定從可能的終點數量最少的線索開始。\
為此，她們需要知道「對於每條線索，符合條件的終點數量有多少個」。\
然而她們不擅長算數，因此找上你求助。你能幫幫他們嗎？

\clearpage

## 輸入
第一行有兩個整數 $n,~q$。\
接下來 $n-1$ 行，每行有兩個整數 $u,~v$，代表 $u$、$v$ 之間有一條不確定方向的箭頭。\
接下來 $q$ 行，每行有三個整數 $x,~y,~z$，描述一條線索。

## 輸出
對於 $q$ 條線索，依序輸出符合條件的終點數量有多少個。

## 輸入限制
- $1 \le n \le 2 \times 10^5$
- $1 \le q \le 2 \times 10^5$
- $1 \le u,~v,~x,~y,~z \le n$
- $u \ne v$

## 子任務
\subtasks

\clearpage

## 範例輸入 1
\testfile{0-01.in}

## 範例輸出 1
\testfile{0-01.out}

## 範例輸入 2
\testfile{0-02.in}

\clearpage

## 範例輸出 2
\testfile{0-02.out}

## 範例輸入 3
\testfile{0-03.in}

\clearpage

## 範例輸出 3
\testfile{0-03.out}
