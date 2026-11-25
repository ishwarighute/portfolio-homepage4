# Step 3: Compile with debugging symbols (-g)
gcc -Wall -Wextra -g leak_demo.c -o leak_demo

# Step 4: Run under Valgrind to detect memory leaks
valgrind --leak-check=full --show-leak-kinds=all ./leak_demo