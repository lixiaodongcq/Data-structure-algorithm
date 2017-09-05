//图的邻接矩阵存储结构

#define MaxVertexNum 100 //顶点的最大值
typedef char VertexType //顶点的数据内行
typedef int EdgeType // 带权图中边上权值的数据类型

typedef struct 
{
	VertexType Vex[MaxVertexNum];//顶点表
	EdgeType Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵，边表
	int VexNum,ArcNum;//图中当前的顶点数目，以及弧数。
	
}MGragh;

//图的邻接表法

typedef struct ArcNode //边表节点
{
	int adjver; //顶点位置
	struct ArcNode *next;
	//InfoType info //权值信息
}ArcNode;

typedef struct VNode
{
	VertexType data;
	ArcNode *first;
}VNode,AdjList[MaxVertexNum];

typedef struct{
	AdjList vertices;
	int VexNum,ArcNum;
}ALGraph;