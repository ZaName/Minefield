# BUG LOG

1. isSafe and get both have errors when the col or row is one too big because the inBounds function does not work right
2. revealAdjacent has an issue where it does not reveal the adjacent bombs, when placing a bomb at (0,0) and revealing at (0,1) it should reveal the bomb but it is not