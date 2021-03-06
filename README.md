# EE538 Final Project - Fall 2021 - TrojanMap

## TrojanMap

This project focuses on using data structures in C++ and implementing various graph algorithms to build a map application.

<p align="center"><img src="img/TrojanMap.png" alt="Trojan" width="500" /></p>

 In this project, we are mainly focusing on the routing algorithms to solve problems like Shortest Path and Traveling Salesman, the problems we are working on are based on a map of area nearby USC, and we have several data points saved in a csv file, and we will mainly manipulate with these data to finish our goal.

---

## The data Structure

Each point on the map is represented by the class **Node** shown below and defined in [trojanmap.h](src/lib/trojanmap.h).

```cpp
class Node {
  public:
    std::string id;    // A unique id assign to each point
    double lat;        // Latitude
    double lon;        // Longitude
    std::string name;  // Name of the location. E.g. "Bank of America".
    std::vector<std::string>
        neighbors;  // List of the ids of all neighbor points.
};

## Test the program
bazel run src/main:main

## Step 1: Autocomplete the location name

```c++
std::vector<std::string> Autocomplete(std::string name);
```

When we implmenting this function, we have to tansfer the object and attempt pointers to lowercase for the convience of searching,
after searching, the out put will be desierd locations.

Flow diagram:
<p align="center"><img src="img/auto.png" alt="Trojan" width="500" /></p>

Examples of step 1:

```shell
**************************************************************

Please input a partial location:l
*************************Results******************************
Lawn
LATTCOrtho Institute
Little Galen Center
Leavey Library
Los Angeles Orthopaedic Hospital
Los Angeles
LycaMobile
Lyons Center
**************************************************************
Time taken by function: 4372 microseconds
```

```shell
Please input a partial location:u
*************************Results******************************
University Park
USC Village Dining Hall
USC Parking
USC Village Gym
USC Fisher Museum of Art
University SDA Church Food Pantry
University Seventh Day Adventist Church
**************************************************************
Time taken by function: 3764 microseconds
```

```shell
Please input a partial location:
*************************Results******************************
Kobunga Korean Grill
Korean Presbyterian Church
Kentucky Fried Chicken
Kaitlyn
**************************************************************
Time taken by function: 4393 microseconds
```
What we learn: It is important to initiallize a string, in this case, is "x", we have to intiallize not only the length,
but also put some "a" into it (other letters are fine too), otherwise it will report an error since we only defined the 
length but not give anything to it.


## Step 2: Find the place's Coordinates in the Map

```c++
std::pair<double, double> GetPosition(std::string name);
```
In this case, we will return the latitude and longtitude of the given location, but it have to have a name,
otherwise it will return (-1,-1).

Examples of step 2:

```shell
Please input a location:ChickfilA
*************************Results******************************
Latitude: 34.0167 Longitude: -118.283
**************************************************************
Time taken by function: 2713 microseconds
```

```shell
Please input a location:Ralphs
*************************Results******************************
Latitude: 34.0318 Longitude: -118.291
**************************************************************
Time taken by function: 6177 microseconds
```

```shell
Please input a location:UCLA
*************************Results******************************
No matched locations.
**************************************************************
Time taken by function: 5310 microseconds
```



## Step 3: CalculateShortestPath between two places

```c++
std::vector<std::string> CalculateShortestPath_Dijkstra(std::string &location1_name,
                                               std::string &location2_name);
std::vector<std::string> CalculateShortestPath_Bellman_Ford(std::string &location1_name,
                                               std::string &location2_name);
```

In this step, we have to find shortest path from one point to another point using two algorithms, the first one is Dijkstra, when we do
Dijkstra, we use one more point at each loop, and try to find the shortest path and distance, and return it.
In the Bellman_Ford algorithm, the idea is pretty same as Dijkstra, but not use the nodes, in Bellman_Ford algorithm, we use vertices,
in each loop we use extra one vertices try to find the shortest path and distance.


Flow diagram of Dijkstra:
<p align="center"><img src="img/Dig.png" alt="Trojan" width="500" /></p>


Flow diagram of Bellman_Ford:
<p align="center"><img src="img/Bf_fowrd.png" alt="Trojan" width="500" /></p>

```shell
Example of step3 (Dijkstra):
```

```shell
**************************************************************
* 3. CalculateShortestPath                                    
**************************************************************

Please input the start location:Ralphs
Please input the destination:ChickfilA
*************************Results******************************
2578244375
5559640911
6787470571
6808093910
6808093913
6808093919
6816831441
6813405269
6816193784
6389467806
6816193783
123178876
2613117895
122719259
6807243574
6807243576
213332111
441895337
441895335
122719255
2613117893
6813405231
122719216
6813405232
4015372486
7071032399
4015372485
6813379479
5237381975
6813379481
7204030702
4015372484
6813379430
6813379429
544671955
21306061
6813379428
6813416122
544671962
21306060
6813379465
1286136428
6813379464
6813379426
1673648390
1673648297
4015423964
6813379452
6813379461
1286136452
6813379459
123327639
6813379460
4141790922
4015423963
1286136447
1286136422
4015423962
6813379494
63068643
6813379496
123241977
4015372479
4015372477
1732243576
6813379548
4015372476
4015372474
4015372468
4015372463
6819179749
1732243544
6813405275
348121996
348121864
6813405280
1472141024
4015372462
6813411586
4015372458
6813411588
1837212101
6820935911
4547476733
The distance of the path is:1.65081 miles
**************************************************************
Time taken by function: 21470696 microseconds
```
<p align="center"><img src="img/dig_rph_chick.png" alt="Target" width="500"/></p>


```shell
**************************************************************
* 3. CalculateShortestPath                                    
**************************************************************

Please input the start location:Korean Presbyterian Church
Please input the destination:Jefferson
*************************Results******************************
358850006
6814958417
123358887
6814958419
2613117887
122719050
122719048
1771004860
1771004834
122719273
122719270
2613117870
2613117869
123178896
123178891
2613117884
122719282
2613117905
122719268
6813405227
123096999
6813405226
6813416157
6816193786
6816193785
6813416156
2613117885
6807374562
122719259
6807243574
6807243576
213332111
441895337
441895335
122719255
2613117893
6813405231
122719216
6813405233
4399698027
4399698026
214470797
4399698025
4399698024
441895675
6813379510
122719213
6813379506
6813379407
2613117879
6813379406
6807905595
6787803635
2613117867
4835551110
6813565296
122719205
6813565294
4835551232
4835551104
4012842272
4835551103
123178841
6813565313
122814435
6813565311
4835551228
6813513565
4835551090
4835551081
6813513564
20400292
6813565320
4835549605
3403035582
63785514
4835549601
2193435045
63785522
2193435055
544348510
544348509
1614922696
123292076
6807381232
3663661790
123281095
4012864453
4147530483
122659031
3663661788
544348520
3663661786
2935827801
122814237
122719192
123254964
123672756
1732340091
33078886
4012726920
4012726919
123120169
123120172
4012726918
4012726917
63785589
4012842270
6804831755
1773954300
The distance of the path is:3.01408 miles
**************************************************************
Time taken by function: 21324964 microseconds
```
<p align="center"><img src="img/exp2.png" alt="Target" width="500"/></p>


```shell
Example of Bellman_Ford:
```
```shell
**************************************************************
* 3. CalculateShortestPath                                    
**************************************************************

Please input the start location:Ralphs
Please input the destination:ChickfilA
*************************Results******************************
2578244375
5559640911
6787470571
6808093910
6808093913
6808093919
6816831441
6813405269
6816193784
6389467806
6816193783
123178876
2613117895
122719259
2613117861
6817230316
3642819026
6817230310
7811699597
5565967545
123318572
6813405206
6813379482
544672028
21306059
6813379476
6818390140
63068610
6818390143
7434941012
4015423966
5690152766
6813379440
6813379466
21306060
6813379469
6813379427
123005255
6807200376
6807200380
6813379451
6813379463
123327639
6813379460
4141790922
4015423963
1286136447
1286136422
4015423962
6813379494
63068643
6813379496
123241977
4015372479
4015372477
1732243576
6813379548
4015372476
4015372474
4015372468
4015372463
6819179749
1732243544
6813405275
348121996
348121864
6813405280
1472141024
6813411590
216155217
6813411589
1837212103
1837212101
6820935911
4547476733
The distance of the path is:1.53852 miles
**************************************************************
Time taken by function: 24438144 microseconds

**************************************************************
```
<p align="center"><img src="img/dig_rph_chick.png" alt="Target" width="500"/></p>


In this comparison, we can see that Dijkstra is faster than Bellman-Ford.

## Step 4: The Traveling Trojan Problem (AKA Traveling Salesman!)


In this problem, we are given several random points, then we have to find the optimal way to make the path as short as possible. In this step, we have to implement three methods, we have finished two of them so far,
one is Brute force, another one is 2-opt.
 
In this step, we have to find the optimal solution to Traveling Salesman problem, which named Traveling Trojan in our final project,
the object of this problem is to find the shortest way between several points, in reality it refers to the delievery related problems.
After this algorithm, we will find the shortest path between these points which can save the time for the delievery man.

- Brute force
```c++
std::pair<double, std::vector<std::vector<std::string>>> TravellingTrojan(
      std::vector<std::string> &location_ids);
```
- [2-opt Heuristic](https://en.wikipedia.org/wiki/2-opt). Also see [this paper](http://cs.indstate.edu/~zeeshan/aman.pdf)
```c++
std::pair<double, std::vector<std::vector<std::string>>> TravellingTrojan_2opt(
      std::vector<std::string> &location_ids);
```

```shell                          
In this task, we will select N random points on the map and you need to find the path to travel these points and back to the start point.
```
```shell    
example of Brute force
```
<p align="center"><img src="img/BruteF.png" alt="Target" width="500"/></p>

```shell    
example of 2-opt
```
<p align="center"><img src="img/2opt.png" alt="Target" width="500"/></p>

In this step, if we put more points, 2-opt will run faster than Bellman-Ford, since we have limited the try time to be 20,
but if we did not set this limit, 2-opt will take much longer time.


## Step 5: Cycle Detection

```c++
bool CycleDetection(std::vector<double> &square);
```

In this function, we first have to create a vector to store points inside the square, then we have to run the helper function that help us to detect if there are cycles in this square.
More specifically, in the helper function, we first have to row out the points outside the circle, and then run this function repeatedly, until we find the cycle, else there is not a circle, we just return false.
 

Example 1:
```shell
Input: square = {-118.298, -118.270, 34.020, 34.010}
Output: true
```
Here we use the whole original graph as our subgraph. 
<p align="center"><img src="img/CD1.png" alt="TSP" width="500"/></p>

Example 2:
```shell
Input: square = {-118.290919, -118.282911, 34.02235, 34.019675}
Output: false
```
Here we use a square area inside USC campus as our subgraph
<p align="center"><img src="img/CD2.png" alt="TSP" width="500"/></p>

Note: You could use the function below to visualize the subgraph. 

```c++
/**
 * PlotPoints: Given a vector of location ids draws the points on the map (no path).
 * 
 * @param  {std::vector<std::string>} location_ids : points inside square
 * @param  {std::vector<double>} square : boundary
 */
void TrojanMap::PlotPointsandEdges(std::vector<std::string> &location_ids, std::vector<double> &square)
```


## Step 6: Topological Sort

```c++
std::vector<std::string> DeliveringTrojan(std::vector<std::string> &location_names,
                                            std::vector<std::vector<std::string>> &dependencies);
```

In this algorithm, we get the locations and the dependencies between them. The dependencies are like constrain to the sort since it tells us which location should be prior to the other one. So here we first choose the point we start, then we go through the path until we approach the end. Then we put the end point into our vector and go back to the previous point to see whether there are other branches. We call this function recursively and finally all the points is in our vector. At last, we just need to reverse our vector then we can get the correct result.


```shell
Example of Toplogical Sort
```

<p align="center"><img src="img/TS.png" alt="TSP" width="500"/></p>


## Step 7: Find K closest points

In this function, we have to find K closest points of given point, the main idea of this function is to calculate the distance between given points and other points, and choose K closest points as the result
  

- Backtracking
```c++
std::vector<std::string> FindKClosestPoints(std::string name, int k);
```

Please report and compare the time spent by this algorithm and show the points on the map.


<p align="center"><img src="img/KCP.png" alt="Kclosest" width="500"/></p>
