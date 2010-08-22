#include <gtest/gtest.h>

#include <010.h>

using std::list;
using std::vector;
using std::pair;
using std::make_pair;

TEST(MarkVertexes, List)
{
    EdgesInfo edges(4);
    for (size_t i = 0; i < edges.size() - 1; ++i)
    {
        edges[i].push_back(i + 1);
    }

    vector<int> marks(4, -1);
    markVertexes(edges, marks, 0, 3, 0);

    ASSERT_EQ(0, marks[0]);
    for (size_t i = 1; i < edges.size(); ++i)
    {
        ASSERT_EQ(i - 1, marks[i]);
    }
}

TEST(MarkVertexes, Tree)
{
    EdgesInfo edges(6);
    edges[0].push_back(1);
    edges[0].push_back(2);
    edges[1].push_back(3);
    edges[1].push_back(4);
    edges[2].push_back(5);

    vector<int> marks(6, -1);
    markVertexes(edges, marks, 0, 4, 0);

    ASSERT_EQ(0, marks[0]);
    ASSERT_EQ(0, marks[1]);
    ASSERT_EQ(1, marks[4]);
}

TEST(GetPath, Tree)
{
    EdgesInfo edges(6);
    edges[0].push_back(1);
    edges[0].push_back(2);
    edges[1].push_back(3);
    edges[1].push_back(4);
    edges[2].push_back(5);

    vector<int> path;
    getPath(edges, 0, 5, path); 

    ASSERT_EQ(3, path.size());
    ASSERT_EQ(0, path[0]);
    ASSERT_EQ(2, path[1]);
    ASSERT_EQ(5, path[2]);
}

TEST(GetPath, NoPath)
{
    EdgesInfo edges(2);

    vector<int> path;
    getPath(edges, 0, 1, path);

    ASSERT_TRUE(path.empty());
}

TEST(CreateGraph, Basic)
{
    vector<pair<int, int> > includes;
    includes.push_back(make_pair(1, 2));
    includes.push_back(make_pair(1, 3));
    includes.push_back(make_pair(1, 4));
    includes.push_back(make_pair(2, 1));
    includes.push_back(make_pair(2, 4));
    includes.push_back(make_pair(3, 3));

    EdgesInfo edges;
    createGraph(3, 4, includes, edges);

    for (int i = 0; i <= 8; ++i)
        edges[i].sort();

    list<int>::const_iterator it = edges[0].begin();
    ASSERT_EQ(1, *it);
    ++it;
    ASSERT_EQ(2, *it);
    ++it;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
