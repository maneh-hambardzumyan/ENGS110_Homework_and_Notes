#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char note[500];


    file = fopen("notes.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }


    printf("Enter your note: ");
    fgets(In our last class, we learned about UNIX and its different system types, including Linux. We also explored various Linux commands, focusing on basic file management, system navigation, and process control, which are essential for efficiently interacting with the terminal., sizeof(note), stdin);


    fprintf(file, "%s\n", note);
    fclose(file);

    system("git add notes.txt");
    system("git commit -m \"Updated notes\"");
    system("git push origin main"); 

    printf("Note saved and pushed to GitHub.\n");

    return 0;
}
