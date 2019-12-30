# 最大团大作业

要求在[这里](./Archive/要求.md)。简要的来讲：

- 码代码（4分）
- 写报告ppt（2分）
  - 简述该问题研究的历史和现状
  - 阅读一篇指定论文，写出其算法实现思想

关于NP-hard问题之间的转化，如果感兴趣可以参考之前算分课上做过的Karp那篇论文的报告。



## Project分析

[OJ](http://dapractise.openjudge.cn/zdt2019test2/1/)上面的数据是顶点数N<=750,边数M<=250000。

N=20,30,40,60,80,100,200,300,400,500,750。

成绩按解的质量给分，例如找到顶点数为8的团，该测试点给8分。目前最高是156分。



随手找了一下：

[寻找图中最大团的最好算法是什么算法（2016年为止）? - 知乎](https://www.zhihu.com/question/55908293)

里面提到的[Bron-Kerbosch algorithm](https://en.wikipedia.org/wiki/Bron–Kerbosch_algorithm)，CSDN上有一篇[文章](https://blog.csdn.net/yo_bc/article/details/77453478)有成型的代码。拿来试了一下，速度不快，暂时只能输出最大团大小，不知道怎么输出编号。



要求里面提到的样例数据所在的网站打不开，用[Internet Archive](https://web.archive.org/web/20180225120644/http://sites.nlsde.buaa.edu.cn/~kexu/benchmarks/graph-benchmarks.htm)保存的网页看了一下，有这些数据：

> - [frb30-15-clq.tar.gz](https://web.archive.org/web/20180225120644/http://sites.nlsde.buaa.edu.cn/~kexu/benchmarks/frb30-15-clq.tar.gz) (  914 KB):  450 vertices - 5 instances, with both the maximum clique size and the chromatic number = 30
> - [frb35-17-clq.tar.gz](https://web.archive.org/web/20180225120644/http://sites.nlsde.buaa.edu.cn/~kexu/benchmarks/frb35-17-clq.tar.gz) ( 1599 KB):  595 vertices - 5 instances, with both the maximum clique size and the chromatic number = 35
> - [frb40-19-clq.tar.gz](https://web.archive.org/web/20180225120644/http://sites.nlsde.buaa.edu.cn/~kexu/benchmarks/frb40-19-clq.tar.gz) ( 2647 KB):  760 vertices - 5 instances, with both the maximum clique size and the chromatic number = 40
> - [frb45-21-clq.tar.gz](https://web.archive.org/web/20180225120644/http://sites.nlsde.buaa.edu.cn/~kexu/benchmarks/frb45-21-clq.tar.gz) ( 4085 KB):  945 vertices - 5 instances, with both the maximum clique size and the chromatic number = 45
> - [frb50-23-clq.tar.gz](https://web.archive.org/web/20180225120644/http://sites.nlsde.buaa.edu.cn/~kexu/benchmarks/frb50-23-clq.tar.gz) ( 6444 KB): 1150 vertices - 5 instances, with both the maximum clique size and the chromatic number = 50
> - [frb53-24-clq.tar.gz](https://web.archive.org/web/20180225120644/http://sites.nlsde.buaa.edu.cn/~kexu/benchmarks/frb53-24-clq.tar.gz) ( 7979 KB): 1272 vertices - 5 instances, with both the maximum clique size and the chromatic number = 53
> - [frb56-25-clq.tar.gz](https://web.archive.org/web/20180225120644/http://sites.nlsde.buaa.edu.cn/~kexu/benchmarks/frb56-25-clq.tar.gz) ( 9774 KB): 1400 vertices - 5 instances, with both the maximum clique size and the chromatic number = 56
> - [frb59-26-clq.tar.gz](https://web.archive.org/web/20180225120644/http://sites.nlsde.buaa.edu.cn/~kexu/benchmarks/frb59-26-clq.tar.gz) (11890 KB): 1534 vertices - 5 instances, with both the maximum clique size and the chromatic number = 59
> 

随手找了一下，发现了去年一组同学做的[源代码](https://github.com/Zachary-ZS/MaxClique)，ID很熟悉，应该是我们这届的。他们的samples里面包括了这些文件，还写了个decode的Tool，可以直接拿来用。

库里面还有他们复现的算法对应的[Paper](./Archive/Local search with edge weighting and configuration checking heuristics for minimum vertex cover.pdf)，里面介绍得比较详细，也包括了「简述该问题研究的历史和现状」这一task的很多信息，可以细看一下。

## 最大团问题分析

解法可分为两类：

- exact
  - branch-and-bound algorithms
  - Exact algorithms guarantee the optimality of the solutions they ﬁnd, but may fail to give a solution within reasonable time for large instances.
- heuristic
  - stochastic local search algorithms
  - heuristic algorithms cannot guarantee the optimality of their solutions, they can solve large and hard MVC (MIS, MC) instances in the sense of giving optimal or near-optimal solutions within reasonable time

”成绩按解的质量给分“，即鼓励使用heuristic way

