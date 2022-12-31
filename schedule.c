#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s INTERVAL COMMAND\n", argv[0]);
    return 1;
  }

  // Intervall in Sekunden aus Argument 1 lesen
  int interval = atoi(argv[1]);
  if (interval <= 0) {
    fprintf(stderr, "Error: INTERVAL must be a positive integer\n");
    return 1;
  }

  // Befehl aus Argument 2 lesen
  char* command = argv[2];

  while (1) {
    // Befehl ausführen
    int result = system(command);
    if (result != 0) {
      fprintf(stderr, "Error: command failed with code %d\n", result);
    }

    // Intervall warten
    sleep(interval);
  }

  return 0;
}
