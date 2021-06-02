# Command Based Text Editor

[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)      [![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com) ![](https://camo.githubusercontent.com/e5031d971f0fe1cfff21f7e99dc0406eecd41b9f294d17db7523340bdf9fcccb/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f56697375616c53747564696f2d3543324439312e7376673f7374796c653d666f722d7468652d6261646765266c6f676f3d76697375616c2d73747564696f266c6f676f436f6c6f723d7768697465)

Our goal in this project is to write a command-based text editor in cpp using [linked lists](https://www.geeksforgeeks.org/data-structures/linked-list/) and [stack](https://www.geeksforgeeks.org/stack-in-cpp-stl/).

This text editor will print the contents of a file to the screen, page by page.

Each page consists of 10 lines. An example image is given below.

![](https://raw.githubusercontent.com/bardakcib/CommandBasedTextEditor/master/res/mainPage.png)

I have implemented a stack to keep track of all actions carried out, so you can undo actions if needed.

Sample txt files are included to the &quot;Resource Files&quot; folder of the project

![](https://raw.githubusercontent.com/bardakcib/CommandBasedTextEditor/master/res/vs2019test.png)

## Main Commands:

![](https://raw.githubusercontent.com/bardakcib/CommandBasedTextEditor/master/res/commandList.png)

- **open filename:** The program should open the file whose name is provided in the field `filename` and loads its contents. For example, if the user enters &quot;_open test.txt_&quot;, your program should open test.txt and load each line in the file to the linked list.

- **save filename:** The program should write the contents of the linked list to the file whose name is provided in the `filename` field.

- **insert n text:** The program should insert a new line with the &quot;text&quot; area user entered to the n_th_ line. For example, if the user enters &quot;insert 5 hello my friend&quot;, your program should insert a new line at line position 5 and put &quot;hello my friend&quot; in that line.

  If the .txt file already contains more than n lines, it should insert thin new line between lines n-1 and n, putting the newly inserted text at line n. If the file contains   
  less than n lines, it should fill the gap with blank lines until the newly inserted line becomes at position n.

- **delete n:** The program should delete the line at position n.

- **move n m:** The program should move the line at position n to new position m.

- **replace n text:** The program should replace the text at line n with the string provided within `text` area.

- **next:** Previous contents of the file should not change, but the program should display the next page.

- **prev:** Previous contents of the file should not change, but the program should display the previous page.

- **undo:** Reverts the last action taken. User should be able to call as many undo commands as s/he likes, and should be able to revert back to the initial state of the file after calling undo action enough times
