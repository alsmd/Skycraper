<h1>Skycraper</h1>

<p>Skycraper is a puzzle game that can be played in a board 3x3 or a maximum of 9x9</p>
<p>You can se how it works <a href="https://www.puzzle-skyscrapers.com/">here</P>
<hr>
<h2>This program can resolve this puzzle using backtracking and bruteforce.</h2>
<h3>You can give the board's rule to find the solution, a board full of 0 is returned if the rule doesn't have a correspond board.</h3>
<ul>
  <li>gcc -I./includes ./srcs/*.c ./srcs/*/*.c -o skycraper</li>
  <li>./skycraper <board size 4-7> <up rule> <down rule> <left rule> <right rule></li>
  <ls>ex: ./skycraper 4 2213 3221 3123 2231</li>
</ul>
