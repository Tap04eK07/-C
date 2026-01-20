Number Guesser — C Implementation

Overview
  A console‑based number guessing game in C. The player selects a difficulty level, then tries to guess a randomly generated number within a limited number of attempts. The game provides feedback (Too low!, Too high!, Correct!) and tracks wins/losses.

Features
  Three difficulty levels (Easy, Medium, Hard).
  Input validation for difficulty selection.
  Attempt counter with remaining attempts display.
  Replay option.
  Final score summary (wins/losses).
  
Requirements
  C compiler (e.g., GCC, Clang).
  Standard C library (stdio.h, stdlib.h, time.h).
  No external dependencies.

How to Compile and Run
  1.Save the code
    Create a file guess_the_number.c and paste the provided C code.
  2.Compile the program
    gcc guess_the_number.c -o guess_the_number 
  3.Run the executable
    guess_the_number
    
Gameplay Instructions
  1.Choose difficulty
    Select 1, 2, or 3 for:
      Easy: 1–50, 10 attempts.
      Medium: 1–100, 7 attempts.
      Hard: 1–200, 5 attempts.
  2.Make guesses:
    Enter integers within the specified range when prompted (>).
  3.Get feedback
    Too low - guess is below the target.
    Too high - guess is above the target.
    Correct - you’ve guessed the number!
  4.Track attempts
    The game shows remaining attempts after each wrong guess.
  5.Play again?
    After a round, type y/Y to restart or n to exit.
  6.View final score
    On exit, the game displays total wins and losses.# -C
  
Code Structure
  main() - Handles game loop, difficulty selection, and score tracking.
  generate_random_number() - Generates a random number in the given range.
  get_user_guess() - Reads and returns the user’s guess.
  check_guess() - Compares guess to target and returns feedback.
  play_game() - Runs a single round with attempt limits.
  display_score() - Prints final wins/losses on exit.

Key Features Explained
  Randomness: srand(time(NULL)) seeds the RNG for unique numbers per run.
  Difficulty Levels: Adjusts range and max attempts via switch statement.
  Input Handling: Uses scanf() with error‑resistant formatting (e.g., " %c" for play_again).
  Attempt Tracking: Stops the loop when attempts are exhausted or the number is guessed.
