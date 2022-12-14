# 騎馬打仗

\begin{figure}[h]
\centering
\includegraphics[width=12cm]{img.jpg}
\caption{堀北鈴音與D班的同學們參加騎馬打仗，出自動畫《歡迎來到實力至上主義的教室~第二季》}
\end{figure}

堀北鈴音就讀於高度育成高等學校，這所特別的學校給予學生們高度的自由，同時學生的任何所作所為都會列入學校的評分當中，因此不僅學力和智力，還有許多特別考試測驗學生們的判斷力、團隊合作等等能力。\
作為一所學校，運動會必定是不可少的，然而連體育能力都列入評分中，所以運動會的規則也十分特別。

以騎馬打仗來說，每個班級都可以自行選定一個數字 $k$，根據座號順序每 $k$ 個人分成一組（座號 $1$ 到 $k$ 一組，$k+1$ 到 $2k$ 一組，以此類推，最後不足 $k$ 人的部分亦分成一組）。\
這表示若每組人數越多，這組的騎手就會越穩固，但馬匹的組數就會減少，反之，也可以用馬匹的組數來換取馬匹的穩定性，所以選定適合的 $k$ 是個大學問。\
為了評估該如何分組，作為D班領導人的鈴音將每個人的能力值量化成一個整數，該組總能力即為該組所有人的能力值總和。\
想必在場上能力最差的那組會成為最先攻擊的目標，所以鈴音想要知道在每 $k$ 個人分成一組時，最差的那組總能力值是多少。

由於 $k$ 的選擇相當多，聰明的鈴音當然不想要自己算，所以這個任務便丟到了你身上，請根據鈴音詢問的 $k$ 值回答答案。

\clearpage

## 輸入
第一行有兩個正整數 $n,~q$，分別是班上人數以及鈴音詢問的次數。\
第二行有 $n$ 個正整數 $a_1,~a_2,~\dots,~a_n$，座號為 $i$ 人的能力值為 $a_i$。\
接下來 $q$ 行，每行有一個正整數 $k$，為鈴音的詢問。

## 輸出
對於每筆詢問，輸出 $k$ 個人一組時，最差組別的總能力值。

## 輸入限制
- $1 \leq n,~q \leq 2 \times 10^5$
- $1 \leq a_i \leq 10^9$
- $1 \leq k \leq 10^9$

## 子任務
\subtasks

\clearpage

## 範例輸入
\testfile{0-01.in}

## 範例輸出
\testfile{0-01.out}
