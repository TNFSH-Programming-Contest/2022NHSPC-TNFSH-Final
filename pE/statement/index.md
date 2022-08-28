#

<!-- \begin{figure}[h]
\centering
\includegraphics[width=2in]{TODO.jpg}
\caption{TODO: 圖片說明}
\end{figure} -->

給你一個數列 $a$ 以及 $q$ 筆詢問，
對於每筆詢問，一共有 $4$ 種 :
1. 把 $x$ 新增到數列的最後面
2. 把 $x$ 新增到數列的最前面
3. 將數列由左到右第 $t$ 次出現的 $x$ 從數列中移除
4. 求 $a_l + a_{l+1} + ... + a_{r-1}+a_r$

\clearpage

## 輸入
輸入第一行有兩個正整數 $n,q$ ，代表數列長度以及詢問次數
輸入第二行有 $n$ 個正整數，代表數列 $a$ ，
接下來 $q$ 行有兩個或三個正整數，其中第一個數為 $type$ ，
若 $type = 1 \; or \; 2$ ，則接下來會有一個正整數 $x$ 。 
若 $type = 3$ ，則接下來會有兩個正整數 $x,t$ 。
$t = 4$，則接下來會有兩個正整數 $l,r$ 。

## 輸出
對於每筆 $type = 4$ 的詢問，輸出一個正整數，代表 $a_l + a_{l+1} + ... + a_{r-1}+a_r$ 。
最後一行輸出操作後的數列 $a$ 。

## 輸入限制
- $1 \leq q,n \leq 10^5$
- $-10^9 \leq a_i \leq 10^9, \forall 1 \leq i \leq n$
- $type \in \{1,2,3,4\}$
- $\forall type \in \{1,2\}$ 的詢問， $-10^9 \leq x \leq 10^9$ 
- $\forall type = 3$ 的詢問， $t \leq x$ 在數列中出現的次數
- $\forall type = 4$ 的詢問， $1 \leq l \leq r \leq a$ 目前的長度

## 子任務
\subtasks

\clearpage

## 範例輸入
```
5 4
1 2 3 4 2
1 2 
2 8
3 2 3
4 2 5
```

## 範例輸出
```
10
8 1 2 3 4 2
```
