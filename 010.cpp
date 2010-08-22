#include <iterator>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <assert.h>

#ifdef EL_JUDGE
#define NDEBUG
#endif

using namespace std;

typedef vector<list<int> > EdgesInfo;

void markVertexes(const EdgesInfo& edges, vector<int>& vertexes, int current, int end, int mark)
{
    //assert(edges.size() == vertexes.size());

    if (vertexes[current] >= 0)
        return;

    vertexes[current] = mark;

    if (current == end)
        return;

    for(list<int>::const_iterator it = edges[current].begin();
        it != edges[current].end(); ++it)
    {
        markVertexes(edges, vertexes, *it, end, current);
    }
}

int getPath(const EdgesInfo& edges, int begin, int end, vector<int>& path)
{
    //assert(path.empty());

    vector<int> vertexes(edges.size(), -1);
    markVertexes(edges, vertexes, begin, end, 1);

    if (vertexes[end] == -1)
        return -1;

    vector<int> revertedPath;
    int current = end;
    while (current != begin)
    {
        revertedPath.push_back(current);
        current = vertexes[current];
    }
    revertedPath.push_back(begin);

    copy(revertedPath.rbegin(), revertedPath.rend(), std::insert_iterator<vector<int> >(path, path.end()));
    return 0;
}

void reversePath(EdgesInfo& edges, const vector<int>& path)
{
    vector<int>::const_iterator edgeBegin = path.begin();
    for (vector<int>::const_iterator edgeEnd = path.begin() + 1;
         edgeEnd < path.end(); ++edgeEnd)
    {
        edges[*edgeBegin].remove(*edgeEnd);
        edges[*edgeEnd].push_back(*edgeBegin);
        edgeBegin = edgeEnd;
    }
}

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void updateFlow(map<pair<int, int>, int>& flow, vector<int>& path)
{
    vector<int>::const_iterator edgeBegin = path.begin();
    for (vector<int>::const_iterator edgeEnd = path.begin() + 1;
         edgeEnd < path.end(); ++edgeEnd)
    {
        int diff = 1;
        int minEdge = *edgeBegin;
        int maxEdge = *edgeEnd;

        if (minEdge > maxEdge)
        {
            swap(minEdge, maxEdge);
            diff = -diff;
        }

        //assert(minEdge <= maxEdge);

        flow[std::make_pair(minEdge, maxEdge)] += diff;

        edgeBegin = edgeEnd;
    }
}

int getMaxFlow(EdgesInfo& edges, map<pair<int, int>, int>& flow, int begin, int end)
{
    vector<int> path;
    int code = getPath(edges, begin, end, path); 
    int flowValue = 0;

    while (code == 0)
    {
        flowValue += 1;
        reversePath(edges, path);
        updateFlow(flow, path);
        path.clear();
        code = getPath(edges, begin, end, path); 
    }

    return flowValue;
}


void createGraph(int cardsCount, int envelopesCount, const vector<pair<int, int> >& includes, EdgesInfo& edges)
{
    const int begin = 0;
    const int end = cardsCount + envelopesCount + 1;

    const int cardsShift = 0;
    const int envelopesShift = cardsCount;

    edges.resize(end + 1);

    for (vector<pair<int, int> >::const_iterator it = includes.begin();
         it != includes.end(); ++it)
    {
        edges[cardsShift + it->first].push_back(it->second + envelopesShift);
    }

    for (int i = 1; i <= cardsCount; ++i)
        edges[begin].push_back(i);

    for (int i = 1; i <= envelopesCount; ++i)
        edges[i + envelopesShift].push_back(end);
}

int getNewYearGreetings(int cardsCount, int envelopesCount, const vector<pair<int, int> >& includes, vector<pair<int, int> >& result)
{
    const int begin = 0;
    const int end = cardsCount + envelopesCount + 1;

    const int cardsShift = 0;
    const int envelopesShift = cardsCount;

    EdgesInfo edges;
    createGraph(cardsCount, envelopesShift, includes, edges);

    map<pair<int, int>, int> flow;
    int flowValue = getMaxFlow(edges, flow, begin, end);

    for (map<pair<int, int>, int >::const_iterator it = flow.begin();
         it != flow.end(); ++it)
    {
        if ((it->first.first != begin) && (it->first.second != end))
        {
            //assert((it->second == 1) || (it->second == 0));
            if (it->second == 1)
            {
                //assert(it->first.first < it->first.second);
                result.push_back(make_pair(it->first.first, it->first.second - envelopesShift));
            }
        }
    }

    return flowValue;
}

#if 0
int main()
{
    int cardsCount, envelopesCount, includesCount;
    cin >> cardsCount >> envelopesCount >> includesCount;

    vector<pair<int, int> > includes;

    istream_iterator<int> it = istream_iterator<int>(cin);
    while (it != istream_iterator<int>())
    {
        pair<int, int> p;
        p.first = *it;
        ++it;
        p.second = *it;
        ++it;
        includes.push_back(p);
    }

    //assert(includes.size() == (size_t)includesCount);

    vector<pair<int, int> > result;
    int flowValue = getNewYearGreetings(cardsCount, envelopesCount, includes, result);

    cout << flowValue << endl;
    for (vector<pair<int, int> >::const_iterator it = result.begin();
         it != result.end(); ++it)
    {
        cout << it->first << ' ' << it->second << endl;
    }
    return 0;
}
#endif
