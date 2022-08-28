# 

<!-- \begin{figure}[h]
\centering
\includegraphics[width=2in]{TODO.jpg}
\caption{TODO: 圖片說明}
\end{figure} -->

在一數線上給定初始座標 $s$ 、移動範圍 $[0, m]$ ， 
每次移動可使座標 $+1$ 或 $-1$ ， 
求移動 $k$ 次後恰好到達座標 $e$ 的方法數?

\clearpage

## 輸入
一行包含四個整數 $m,s,e,k$。
$m$ 代表移動範圍， $s$ 代表起點座標， $e$ 代表目標終點座標， $k$ 代表移動次數。

## 輸出
輸出有多少種走法mod $10^9+7$ 。

## 輸入限制
 - $1 \leq k \leq 10^6$
 - $1 \leq m \leq 10^6$
 - $0 \leq s, e \leq m$

## 子任務
\subtasks

\clearpage

## 範例輸入 1
```
4 2 2 6
```

## 範例輸出 1
```
18
```

## 範例輸入 2
```
10 8 2 10
```

## 範例輸出 2
```
45
```
