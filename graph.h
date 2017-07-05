typedef struct Graph{
	EdgeCell *first;
	EdgeCell *last;
} Graph;

typedef struct Edge{
	 int vertexA;
	 int vextexB;
} Edge;

typedef struct EdgeCell{
	Edge edge;
	struct EdgeCell *next;
} EdgeCell;