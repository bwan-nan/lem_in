# lem_in

Lem_in is an algorithm project about graph traversal and max-flow optimization.</br></br>
You start with a given number of ants, all inside a 'Start-room' of an anthill.</br>
The goal is to make all ants go from Start to End-room with the minimum number of movements.</br>
An anthill is composed of 'rooms' (or nodes in a graph) and each room is linked to other rooms by 'tunnels' (or edges).
</br>**The trick is that a room (except for Start and End) can only welcome 1 ant at a time.**

## Visual
You can type ```./visual.sh [existing_map]``` or ```./visual.sh --flow-thousand``` (using the generator).</br>
```./generator --help``` </br>
![alt text](https://github.com/bwan-nan/lem_in/blob/master/small-map.gif)

## Input
```
10          // Number of ants
A 200 200   // Room name (1) ants it's X-Y coordinates
B 550 150
C 550 450
##start     // Next room will be Start room
D 250 450
##end       // Next room will be End room
E 850 450
F 850 150
A-B         // Room 1 and 2 are linked by a tunnel
A-C
A-D
B-D
B-F
B-E
C-D
C-E
C-F
E-F
```

## Output
L[ant]-[room]
```
L1-B L2-C       //Round 1 : Ant number 1 goes to room B. Ant number 2 goes to room C.
L1-E L2-E L3-B L4-C
L3-E L4-E L5-B L6-C
L5-E L6-E L7-B L8-C
L7-E L8-E L9-B L10-C
L9-E L10-E
```

## Algorithm

We modified Ford-Fulkerson and Edmonds-Karp max-flow algorithm to fit our problem. 
We use a BFS (Breadth First Search) to search for the shortest path in the graph.
What we do is:
- As soon as we find the shortest path, we test the solution:</br>
 -> We want to see how many rounds it would take the ants to go from Start to End room using only this path.</br>
- Then we block this path in the graph and we look for the 2nd shortest path. If/ounce we found it, we test again the new solution:</br>
 -> If it takes less rounds to go from Start to End using 2 paths instead of 1, then this solution is better and we continue searching for 3 paths, 4 paths, etc...</br>
 -> Else, the new solution is not better than the previous one, so we keep the previous one.
 
 ## Example
 ```./lem_in --paths maps/tricky2```
 
```
Initialized 1 path:
This solution would take 23 rounds        // 23 rounds using 1 path
#  1: A-B-C-End
Initialized 2 paths:
This solution would take 15 rounds        // 15 rounds using 2 paths (15 < 23, so we keep searching)
#  2: A-B-C-End
#  3: K-4-M-N-O-P-End
Initialized 3 paths:
This solution would take 12 rounds        // 12 rounds using 3 paths (12 < 15, so we keep searching)
#  5: D-E-B-C-End
#  4: A-G-H-I-J-End
#  6: K-4-M-N-O-P-End
Initialized 4 paths:
This solution would take 12 rounds        // 12 using 4 paths so we keep the previous solution (3 paths)

L1-D L2-A L3-K
L1-E L2-G L3-4 L4-D L5-A L6-K
L1-B L2-H L3-M L4-E L5-G L6-4 L7-D L8-A L9-K
L1-C L2-I L3-N L4-B L5-H L6-M L7-E L8-G L9-4 L10-D L11-A L12-K
L1-End L2-J L3-O L4-C L5-I L6-N L7-B L8-H L9-M L10-E L11-G L12-4 L13-D L14-A L15-K
L2-End L3-P L4-End L5-J L6-O L7-C L8-I L9-N L10-B L11-H L12-M L13-E L14-G L15-4 L16-D L17-A
L3-End L5-End L6-P L7-End L8-J L9-O L10-C L11-I L12-N L13-B L14-H L15-M L16-E L17-G L18-D L19-A
L6-End L8-End L9-P L10-End L11-J L12-O L13-C L14-I L15-N L16-B L17-H L18-E L19-G L20-D
L9-End L11-End L12-P L13-End L14-J L15-O L16-C L17-I L18-B L19-H L20-E
L12-End L14-End L15-P L16-End L17-J L18-C L19-I L20-B
L15-End L17-End L18-End L19-J L20-C
L19-End L20-End
```
</br>
