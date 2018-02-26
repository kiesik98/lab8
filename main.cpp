#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
using namespace std;

long long size, count, fcount;

void dfs(){
    DIR* dp = opendir(".");
    struct dirent *res;

    while ((res = readdir(dp))!= NULL) {
            if (strcmp(res->d_name, ".")==0 || strcmp(res->d_name, "..")==0)
                continue;

        struct stat st;
        stat(res->d_name, &st);
        if (S_ISDIR(st.st_mode)){
            cout << "DIR ";
            fcount++;
        } else {
            size += st.st_size;
            count++;
            }


   }

    closedir(dp);
}

int main()
{
    dfs();
    cout << count <<" files, " << fcount << " dirs, " << size << " bytes.\n";
    return 0;
}


