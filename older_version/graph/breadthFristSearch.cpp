// 广度优先遍历————BFS
#include "graph_struct_define_matrix.h"
#include "graph_struct_define_list.h"

// 1.邻接表表示的无向图广度优先遍历连通图（非递归）：类似于树的层次遍历（队列实现）
#include <stdbool.h>
#define graph_vertex_num 9  // 需要遍历的图的结点总数
bool visited[graph_vertex_num] = { FALSE };
// 辅助数组：记录以访问结点，初始化为FALSE，以访问标记TRUE

