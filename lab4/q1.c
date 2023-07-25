#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <ctype.h>

int is_pid_dir(const struct dirent *entry) {
    const char *p;

    for (p = entry->d_name; *p; p++) {
        if (!isdigit(*p))
            return 0;
    }

    return 1;
}

int main(void) {
    DIR *procdir;
    FILE *fp;
    struct dirent *entry;
    char path[256 + 5 + 6]; // d_name + /proc + /stat because in linux file name cannot be greater than 256 + proc+stat
    int pid;
    procdir = opendir("/proc");
    if (!procdir) {
        printf("opendir failed");
        return 1;
    }

    while ((entry = readdir(procdir))) {
        if (!is_pid_dir(entry))
            continue;

        // Try to open /proc/<PID>/stat.
        snprintf(path, sizeof(path), "/proc/%s/stat",entry->d_name);
        fp = fopen(path, "r");

        if (!fp) {
            continue;
        }

        fscanf(fp, "%d %s",
            &pid, path
        );

        printf("%d %s %s\n", pid,"    ", path);
        fclose(fp);
    }

    closedir(procdir);
    return 0;
}

