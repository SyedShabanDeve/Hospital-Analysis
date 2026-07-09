# Dynamic Programming & Greedy Algorithms

| Field | Details |
|---|---|
| **Student Name** | Syed Shaban |
| **SAP ID** | 80414 |
| **Subject** | Design and Analysis of Algorithms |
| **Instructor** | Sir Karar Haider |

## Files

| File | Technique | Description |
|---|---|---|
| `EggDroppingPuzzle.cpp` | Dynamic Programming | Finds the minimum number of trials to find the critical floor with `n` eggs and `k` floors |
| `JobSequencing.cpp` | Greedy | Schedules jobs with deadlines and profits into time slots to maximize total profit |

## How to Compile & Run

```bash
g++ EggDroppingPuzzle.cpp -o eggdrop && ./eggdrop
g++ JobSequencing.cpp -o jobseq && ./jobseq
```

### Expected Output

- **Egg Dropping** (2 eggs, 10 floors): `Minimum trials with 2 eggs and 10 floors: 4`
- **Job Sequencing** (deadlines `{2,1,2,1,1}`, profits `{100,19,27,25,15}`): `Jobs scheduled: 2, Total profit: 127`
