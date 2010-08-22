#include <vector>
#include <list>

typedef std::vector<std::list<int> > EdgesInfo;

void markVertexes(const EdgesInfo& edges, std::vector<int>& vertexes, int current, int end, int mark);
int getPath(const EdgesInfo& edges, int begin, int end, std::vector<int>& path);
void createGraph(int cardsCount, int envelopesCount, const std::vector<std::pair<int, int> >& includes, EdgesInfo& edges);
