# NLP TOOL

Simple NLP tool to perform POS tagging on text.
You can easily train the model with your own annotated text.

Base POS tagging program from [Lapos-0.1.2 by Tsuruoka](https://www.logos.ic.i.u-tokyo.ac.jp/~tsuruoka/lapos/).

This tool improves POS tagging with the ability to understand complex data such as dates, GPS coordinates, URLs, etc.

Additionally, we provide a simple GUI to use this tool:
```bash
$ ./nlpTool -gui
```
## How to install and clean:
```bash
$ ./buildProj.sh -j N (if you want to compile with threads)
```
```bash
$ ./buildProj.sh clean
```
## How to use it:

The basic command is:
```bash
$ ./nlpTool
```
Flags:
```bash
[-t/-text] [input text]     // Input text for POS tagging
[-v/-verbose]               // Turn on verbose mode
```
## Example:

Input:
```bash
$ ./nlpTool -t "Hello world!" -v
```
Output:

```bash
loading ./lapos-0.1.2/model_big/model.la...done
out: loading the models from the directory "./lapos-0.1.2/model_big/" ...done
hello/CD world/NN !/.

hello | CD
world | NN
! | .
hello/CD world/NN !/. 
```

Note: Tags may vary depending on the Lapos model used.

## License:

This project is licensed under the MIT licence. You can consult the complete text of the licence in the file [LICENSE](LICENSE).
