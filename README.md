# Research_Paper_Implementation
Implemented the paper : 
The Subset-Sum Problem: Revisited with an Improved
Approximated Solution



# Proposed Algorithm for the research paper 
1.Sort the numbers in ascending order.
2. Remove the elements which are greater than the target sum.
3. Start from the right hand side initially , which is the largest number.
4. Move leftwards until we find a number whose partial sum comes out to
be less than or equal to the target sum.
5. If you find such a number , include it in the subset and put 1 under
them.
6. Repeat these steps starting from the left until you find ‘01’ after a
group of zeroes.
7. Then move to the left by one step. And repeat the steps 4 to 5 until all
the subsets are found.

![image](https://user-images.githubusercontent.com/68320786/124069060-3faa4500-da59-11eb-8d3d-07db02463b5b.png)
