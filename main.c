#include <stdio.h>
#include <string.h>

#include "colors.h"

#include <sys/sysinfo.h>


int main() {
  char b_distro[256];
  char b_kernel[256];
  char b_user[256];
  char b_hostname[256];
  char b_uptime[256];

  // struct sysinfo info;
  //
  // sysinfo(&info);
  //
  // printf("%ld\n", info.uptime);

 // Get user
  FILE *user = popen("whoami", "r");
  fgets(b_user, sizeof(b_user), user);
  pclose(user);
  b_user[strcspn(b_user, "\n")] = 0;
  
  // Get hostname
  FILE *hostname = popen("hostname", "r");
  fgets(b_hostname, sizeof(b_hostname), hostname);
  pclose(hostname);
  b_hostname[strcspn(b_hostname, "\n")] = 0;
  printf("%s%s%s@%s%s\n", BOLD, MAGENTA, b_user, b_hostname, RESET);


  // Get distro name
  FILE *distro = popen("grep '^NAME=' /etc/os-release | cut -d'=' -f2 | tr -d '\"'", "r");
  fgets(b_distro, sizeof(b_distro), distro);
  pclose(distro);
  b_distro[strcspn(b_distro, "\n")] = 0;
  printf("%s%sOS:%s %s\n", BOLD, MAGENTA, RESET, b_distro);

  // Get kernel version
  FILE *kernel = popen("uname -r", "r");
  fgets(b_kernel, sizeof(b_kernel), kernel);
  pclose(kernel);
  b_kernel[strcspn(b_kernel, "\n")] = 0;
  printf("%s%sKernel:%s %s\n", BOLD, MAGENTA, RESET, b_kernel);

 


  // uptime
  FILE *uptime = popen("uptime -p", "r");
  fgets(b_uptime, sizeof(b_uptime), uptime);
  pclose(uptime);
  b_uptime[strcspn(b_uptime, "\n")] = 0;
  printf("%s%sUptime:%s %s\n", BOLD, MAGENTA, RESET, b_uptime);
  
  return 0;
}
