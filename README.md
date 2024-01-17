# Word_Guesser
A Hang The Man Game developed in C++, where the computer thinks of a country/city and the player guesses letters to reveal the name while avoiding mistakes, with constraints on character repetition and a maximum of 11 chances.

Hang The Man Game
Developed by Junaid Saleem

Introduction:
Hang The Man is a text-based game where the computer thinks of a country or city name, and the player tries to guess the letters to reveal the hidden word. The game follows certain instructions and constraints to provide an engaging and challenging experience.

Instructions:
1. At the beginning of the game, the computer will choose a random country or city name and display underscores (_) representing the letters of the word.
2. The player can enter any character as their guess.
3. If the chosen character is not part of the hidden word, the player loses one chance out of a total of 8 chances. With each mistake, one component of the hangman's body is displayed.
4. If the chosen character is in the word, it will replace the corresponding underscore(s) in the displayed word.
5. The player continues guessing letters until they either reveal the complete word or run out of chances.
6. The game will display the number of chances remaining after each guess and clear the screen to show the updated information.
7. The game ends when the player either correctly guesses the word or runs out of chances and completes the hangman's body.
8. Upon completion, the game will show the result, indicating whether the player won or lost, along with the correct answer, which is the name of the country or city.

Constraints:
1. Once a character is chosen, it cannot be selected again.
2. The maximum number of mistakes allowed is 11, corresponding to the completion of the hangman's body.
3. The game provides a visual representation of the hangman's body using the following format:
   / | \
     |
    / \

Note: This game does not use any built-in string processing functions.

Enjoy playing the Hang The Man game and have fun guessing the country or city names!
