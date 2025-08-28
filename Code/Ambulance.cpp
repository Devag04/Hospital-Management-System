#include "Ambulance.h"

const int MAX_CITIES = 100;
map<string, int> cityToIndex;
map<int, string> indexToCity;
map<string, vector<pair<string, int>>> graph;
int cityCount = 0;

// function to add distances between cities
void addRoad(const string &cityA, const string &cityB, int distance)
{
    if (cityToIndex.find(cityA) == cityToIndex.end())
    {
        cityToIndex[cityA] = cityCount;
        indexToCity[cityCount] = cityA;
        cityCount++;
    }
    if (cityToIndex.find(cityB) == cityToIndex.end())
    {
        cityToIndex[cityB] = cityCount;
        indexToCity[cityCount] = cityB;
        cityCount++;
    }

    // Add road using city names, not indices
    graph[cityA].push_back({cityB, distance});
    graph[cityB].push_back({cityA, distance}); // bi-directional
}


// function to find the shortest path using Dijkstra's algorithm
void shortestPath(const string &src, const string &dest)
{
    if (graph.find(src) == graph.end() || graph.find(dest) == graph.end())
    {
        cout << "One or both cities not found.\n";
        return;
    }

    map<string, int> dist;
    map<string, string> parent;

    for (const auto &pair : graph)
        dist[pair.first] = INT_MAX;

    dist[src] = 0;

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        pair<int, string> current = pq.top();
        pq.pop();
        int d = current.first;
        string u = current.second;

        for (const auto &neighbor : graph[u])
        {
            string v = neighbor.first;
            int w = neighbor.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[dest] == INT_MAX)
    {
        cout << "No path exists.\n";
        return;
    }

    cout << "Shortest Distance: " << dist[dest] << " km\nPath: ";
    vector<string> path;
    for (string at = dest; !at.empty(); at = parent[at])
        path.push_back(at);
    reverse(path.begin(), path.end());

    for (size_t i = 0; i < path.size(); ++i)
        cout << path[i] << (i + 1 < path.size() ? " -> " : "\n");
}


void displayAvailableCities()
{
    set<string> uniqueCities;

    for (auto it = graph.begin(); it != graph.end(); ++it)
    {
        string city = it->first;
        vector<pair<string, int>> neighbors = it->second;

        uniqueCities.insert(city);
        for (const auto &neighbor : neighbors)
        {
            string neighborCity = neighbor.first;
            uniqueCities.insert(neighborCity);
        }
    }

    cout << "\nAvailable Cities:\n";
    for (const auto &c : uniqueCities)
        cout << "- " << c << "\n";
    cout << endl;
}


// ambulance system
void ambulanceRoutingMenu()
{
    int choice;
    do
    {
        cout << "\n--- Ambulance Routing ---\n";
        cout << "1. Add Road Between Cities\n2. Find Shortest Path\n3. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(); // flush newline

        if (choice == 1)
        {
            string cityA, cityB;
            int dist;
            cout << "Enter City A: ";
            getline(cin, cityA);
            cout << "Enter City B: ";
            getline(cin, cityB);
            cout << "Enter Distance (in km): ";
            cin >> dist;
            addRoad(cityA, cityB, dist);
            cout << "Road added.\n";
        }
        else if (choice == 2)
        {
            if (graph.empty())
            {
                cout << "No roads added yet.\n";
                continue;
            }
            displayAvailableCities();
            string src, dest;
            cout << "Enter Source City: ";
            getline(cin, src);
            cout << "Enter Destination City: ";
            getline(cin, dest);
            shortestPath(src, dest);
        }
    } while (choice != 3);
}