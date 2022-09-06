#Title: 100 doors

#Initial condition : all 100 doors are initially closed. You make 100 passes by the doors
#On the first pass : you visit every door in sequence and toggle its state (ig the door is closed, you open it; it it is open, you close it)
#On the second pass: You only visit every second door (door 2, 4, 6, ..) and toggle it.
#On the third time, you visit every third door (door 3, 6, 9, …).
#Continue this pattern until you only visit the 100th door.

#Question - Which doors are open and which are closed after the last pass.

#intial state of the door (closed) 
#There are 101 doors as I want to map door # with the problem, and do not do extra handling on 0 based index.
doors = [False]* 101

# print(doors)
# for i in range (1, 101):
#     doors[i] = not doors[i]
#     print("i = ", i, doors[i])

#print(doors)

#flip the doors 
for i in range (1, 101):
    for j in range (i, 101, i):
        doors[j] = not doors[j];

for i in range (1, 101):
    if doors[i] is True:
        print(i, end=", ");

for i in range(5):
 for j in range(3):
         print(i,j)
