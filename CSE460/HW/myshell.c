/**
Name : Hyeongjun Yang
Studnet ID : 005897537
Date : 05/06/2020
Purpose : This program is for homework 1 in CSE 460, it is the shell script that has functions. There are builtin fucntions like cd, help, exit, setshellname, setterminator, newname, listnewnames, savenewnames, and readnewnames. User can change names for builtin commands and original linux commands and then those commands that names are changed can be checked using listnewnames. Those names also can be written in the file by using listnewnames command. Finally, user can check what they save in the file by using readnewnames command. Therefore, the purpose of this program is to change names for some stuff.
 
Information for original programmer for this code.
@author Stephen Brennan
@website https://brennan.io/2015/01/16/write-a-shell-in-c/
*/


#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

char *shellname = "myshell";
char *terminator = ">";


/*
  Function Declarations for builtin shell commands:
 */
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_STOP(char **args);
int setshellname(char **args);
int setterminator(char **args);
int newname(char **args);
int listnewnames(char **args);
int savenewnames(char **args);
int readnewnames(char **args);
/**
    It is a list for builtin and linux commands. It helps function to change names for commands by
    adding, comparing and changing elements in array. However, original things like builtin and
    linux commands are not changed and only elemnets in newnames and newcommands are changed for new
    names. In case of lsh_num_builtins, it is used for to know number of elements in builtin array.
 */
char *builtin_str[] =
{
  "cd",
  "help",
  "STOP",
  "setshellname",
  "setterminator",
  "newname",
  "listnewnames",
  "savenewnames",
  "readnewnames"
};

//It is the array for new name of builtin commands.
char *newnames_str[10] =
{
  "cd",
  "help",
  "STOP",
  "setshellname",
  "setterminator",
  "newname",
  "listnewnames",
  "savenewnames",
  "readnewnames"
};

//It is the array for linux commands.
char *commands[10] =
{
};

//It is the array for new name of linux commands.
char *newcommands[10] =
{
};

int (*builtin_func[]) (char **) =
{
  &lsh_cd,
  &lsh_help,
  &lsh_STOP,
  &setshellname,
  &setterminator,
  &newname,
  &listnewnames,
  &savenewnames,
  &readnewnames
};

//A function to get size for builtin array.
int lsh_num_builtins()
{
  return sizeof(builtin_str) / sizeof(char *);
}


/*
  Builtin function implementations.
*/

/**
Purpose : It is a function for change directory, so user can change directory by using "cd" command. It also includes part for error, so if user do not enter a argument, it will print message for error.
Parameter(s) : Parameters are list of args, so args[0] is "cd" and args[1] is name of the directory.
Return : It always returns 1, so this program continues executing.
*/
int lsh_cd(char **args)
{
  //Error message is printed when an argument is not enough.
  if (args[1] == NULL)
  {
    printf("You need to put the argument.\n");
  }
  else
  {
    if (chdir(args[1]) != 0)
    {
      perror("lsh");
    }
  }
  
    return 1;
}


/**
Purpose : It shows list of builtin commands in this program. Therefore, user can understand and use  this program easily.
Parameter(s) : Although it has list of args for parmeter, but this parameter do nothing in this function.
Return : It always returns 1, so this program continues executing.
 */
int lsh_help(char **args)
{
  int i;
  printf("Hyeongjun's LSH\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < lsh_num_builtins(); i++) //Print elements in builtin array.
  {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}


/**
Purpose : It is a function to finish excuting.
Parameter(s) : Although it has list of args for parmeter, but this parameter do nothing in this function.
Return : It retrun 0, so it make program exit.
 */
int lsh_STOP(char **args)
{
  return 0;
}


/**
Purpose : It is a functio to change shellname, so user can change shellname by using this function. Before use change shellname, the basic shellname is "myshell".
Parameter(s) : It has list of args, so args[0] is "setshellname" and args[1] is shellname that is new name for shellname.
Return : It always returns 1, so this program continues executing.
 */
int setshellname(char **args)
{
  if (args[1] == NULL)     //A basic shell name.
    shellname = "myshell";
  else
    shellname = args[1];   //A changed shell name.
      
  return 1;
}


/**
Purpose : It is a functio to change terminator, so user can change terminator by using this function. Before use change terminator, the basic shellname is ">".
Parameter(s) : It has list of args, so args[0] is "setterminator" and args[1] is terminator that is new name for termiantor.
Return : It always returns 1, so this program continues executing.
 */
int setterminator(char **args)
{
  if (args[1] == NULL)
    terminator = ">";      //A basic terminator.
  else
    terminator = args[1];  //A changed terminator.

  return 1;
}


/**
Purpose : It is a functio to change name for commands, so user can change names for commands by using this function. There are two cases to change name. One case is for builtin commands and other case is for linux command. Generally, this function changes name for commands by comparing between builtin_str and newnames_str for builtin commands, and commands and newcommands for linux commands. Therefore, newnames_str and newcommands are changed when user want to change names and builtin_str and commands are excuted by comparing with newnames_str and newcommands.
Parameter(s) : It has list of args, so args[0] is "newname", args[1] is the new name for commands, and args[2] is the original name for commands.
Return : It always returns 1, so this program continues executing.
 */
int newname(char **args)
{
  int c = 0;
  
  //Give error when arguments are not enough.
  if (args[1] == NULL || args[2] == NULL)
  {
    printf("Arguments are needed.\n");
  }
  else
  {
    /* Checking between input and builtin functions
    if there are same element, put to array for newname.*/
    for (int i = 0; i < lsh_num_builtins(); i++)
    {
      if (strcmp(args[2], builtin_str[i]) == 0)
      {
        newnames_str[i] = args[1];
        return 1;
      }
    }
     
    /* if input is not builtin command, input are added to two array for linux command.
       one array is for original name for linux command, and other one is for new name for
       linux command. */
    for (int i = 0; i < sizeof(newcommands) / sizeof(newcommands[0]); i++)
    {
      if (commands[0] == NULL)
      {
        commands[0] = args[2];
        newcommands[0] = args[1];
        break;
      }
      else if (commands[i] == args[2])
      {
        commands[i] = args[2];
        newcommands[i] = args[1];
        break;
      }
      else if ((commands[i] != args[2]) && (commands[i] == NULL))
      {
        commands[i] = args[2];
        newcommands[i] = args[1];
        break;
      }
    }
  }
    
  return 1;
}


/**
Purpose : It is a functio to list new names that user made, so user can list new names by using this function.
Parameter(s) : Although it has list of args for parmeter, but this parameter do nothing in this function.
Return : It always returns 1, so this program continues executing.
 */
int listnewnames(char **args)
{
  int j = 0;
  int c = 0;
    
  /*If names are different in builtin array and new name array, it means a command has new name
    Therefore, it is printed as new name.*/
  for (int i = 0; i < lsh_num_builtins(); i++)
  {
    if (strcmp(builtin_str[i],newnames_str[i]) != 0)
    {
      printf("%s ", newnames_str[i]);
      printf("%s\n", builtin_str[i]);
      c++;
    }
        
  }
  
  /*It works like above part, but this one is for linux commands.*/
  while (commands[j] != NULL)
  {
    printf("%s ", newcommands[j]);
    printf("%s\n", commands[j]);
    j++;
    c++;
  }
   
  //If there are no new name, it prints message for it.
  if (c == 0)
  {
    printf("There are no new names. Make some new names.\n");
  }
    
  return 1;
}


/**
Purpose : It is a functio to save new names, so user can save new names by using this function. This function makes file to save new names.
Parameter(s) : It has list of args, so args[0] is "savenewnames" and args[1] is filename that user choose.
Return : It always returns 1, so this program continues executing.
 */
int savenewnames(char **args)
{
    
  int j = 0;
  int c = 0;
   
  //Error handling for not enough arguments.
  if (args[1] == NULL)
  {
    printf("Filename to write is needed.\n");
  }
  else  //if there is no error for argument, it open file and save the new name to that file.
  {
    FILE *wn = fopen(args[1], "wx");
    if (wn == NULL) //If there is error or file exists, error happen.
    {
      printf("Couldn't open file or file already exists.\n");
      return 1;
    }
    //By comparing arrays, only new names are written in the file.
    for (int i = 0; i < lsh_num_builtins(); i++)
    {
      if (strcmp(builtin_str[i], newnames_str[i]) != 0)
      {
        fputs(newnames_str[i], wn);
        fputs(" ", wn);
        fputs(builtin_str[i], wn);
        fputs("\n", wn);
        c++;
      }
    }
    //It works in the same way, but it is for linux commands.
    while (commands[j] != NULL)
    {
      fputs(newcommands[j], wn);
      fputs(" ", wn);
      fputs(commands[j], wn);
      fputs("\n", wn);
      j++;
      c++;
    }
    
    fclose(wn);
    //print message when there is no new name to write.
    if (c == 0)
    {
      printf("There are nothing to write on the file. Check your new names.\n");
    }
  }
 
  return 1;
}

/**
Purpose : It is a function to read new names in the file, so user can look at new names by using this function. Filename name for this function is the filename that user made by using "savenewnames" function.
Parameter(s) : It has list of args, so args[0] is "readnewnames" and args[1] is filename that user made by using "savenewnames" function.
Return : It always returns 1, so this program continues executing.
 */
int readnewnames(char **args)
{
  char buffer[100];
  //Error happen when arguments are not enough.
  if (args[1] == NULL)
  {
    printf("Filename to read is needed.\n");
  }
  else
  {
    FILE *rn = fopen(args[1], "r");
    //It prints error when there is problem for file to open.
    if (rn == NULL)
    {
      printf("There is error to open file. Check your file to open.\n");
      return 1;
    }
    //Print message when there is nothing in the file and name is wrong.
    if (fgets(buffer, sizeof(buffer), rn) == NULL)
    {
      printf("There are nothing in your file. Check your file name or contents.\n");
    }
    else
    {
      /*Read and print the contents in the file. We need to print buffer one time
      because we used fgets to check if statement, so it is for first line.*/
      printf("%s", buffer);
      while (fgets(buffer, sizeof(buffer), rn) != NULL)
      {
        printf("%s", buffer);
      }
    }
  
    fclose(rn);
  }
    
  return 1;
}

/**
Purpose :  Launch a program and wait for it to terminate.
Parameter(s) : Parameters are list of array that are null terminated.
Return : It always returns 1, so this program continues executing.
 */
int lsh_launch(char **args)
{
  pid_t pid;
  int status;


  pid = fork();
  if (pid == 0)
  {
    // Child process
    if (execvp(args[0], args) == -1)
    {
      perror("lsh");
    }
    exit(EXIT_FAILURE);
  }
  else if (pid < 0)
  {
    // Error forking
    perror("lsh");
  }
  else
  {
    // Parent process
    do
    {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

/**
Purpose :  It execute builtin command or launch program.
Parameter(s) : Parameters are list of array that are null terminated.
Return : When the shell should run, it return 1. However, it return 0 when it terminates.
 */
int lsh_execute(char **args)
{
  int i;
  int j = 0;
    
  if (args[0] == NULL)
  {
    // An empty command was entered.
    return 1;
  }

  //Checking builtin command first to execute.
  for (i = 0; i < lsh_num_builtins(); i++)
  {
    if (strcmp(args[0], newnames_str[i]) == 0)
    {
      return (*builtin_func[i])(args);
    }
  }
    
   /*Checking linux command to execute if there is same name in array for new commands, it puts original command name to args[0] to execute that command.*/
   while (commands[j] != NULL)
   {
     if (strcmp(args[0], newcommands[j]) == 0)
     {
       args[0] = commands[j];
     }
     j++;
   }
        
  return lsh_launch(args);
}

/**
Purpose : It is a fucntio to read the line.
Parameter(s) : There is no prarameter.
Return : It returns line from stdin.
 */
char *lsh_read_line(void)
{
#ifdef LSH_USE_STD_GETLINE
  char *line = NULL;
  ssize_t bufsize = 0; // have getline allocate a buffer for us
  if (getline(&line, &bufsize, stdin) == -1)
  {
    if (feof(stdin))
    {
      exit(EXIT_SUCCESS);  // We recieved an EOF
    }
    else
    {
      perror("lsh: getline\n");
      exit(EXIT_FAILURE);
    }
  }
  return line;
#else
#define LSH_RL_BUFSIZE 1024
  int bufsize = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer)
  {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1)
  {
    // Read a character
    c = getchar();

    if (c == EOF)
    {
      exit(EXIT_SUCCESS);
    }
    else if (c == '\n')
    {
      buffer[position] = '\0';
      return buffer;
    }
    else
    {
      buffer[position] = c;
    }
    position++;

    // If we have exceeded the buffer, reallocate.
    if (position >= bufsize)
    {
      bufsize += LSH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer)
      {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
#endif
}

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
/**
Purpose : Spliting a line into tokens.
Parameter(s) : The line.
Return : Null-terminated array of tokens.
 */
char **lsh_split_line(char *line)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token, **tokens_backup;

  if (!tokens)
  {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL)
  {
    tokens[position] = token;
    position++;

    if (position >= bufsize)
    {
      bufsize += LSH_TOK_BUFSIZE;
      tokens_backup = tokens;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens)
      {
        free(tokens_backup);
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

/**
Purpose : Loop gets input and excutes it.
Parameter(s) : There is no prarameter.
Return : There is no return.
 */
void lsh_loop(void)
{
  char *line;
  char **args;
  int status;

  do
  {
      printf(" %s %s ", shellname, terminator);
      line = lsh_read_line();
      args = lsh_split_line(line);
      status = lsh_execute(args);

    //free(line);
    //free(args);
  } while (status);
}

/**
Purpose : It is a main fucntion in this program.
Parameter(s) : argc is number of arguments and argv is a vector of array.
Return : It returns a status code.
 */
int main(int argc, char **argv)
{
  // Load config files, if any.

  // Run command loop.
  lsh_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}
