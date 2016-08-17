#pragma once

struct passwd {
  char* pw_shell;
  char* pw_name;
  char* pw_dir;
};

void endpwent();
