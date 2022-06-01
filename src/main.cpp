#include <fmt/format.h>
#include <iostream>
#include <string_view>
#include <toml.hpp>

int main() {
  static constexpr std::string_view package = R"toml(
[[package]]
url = "https://github.com/junegunn/fzf/releases/download/0.30.0/fzf-0.30.0-linux_amd64.tar.gz"
type = "tar.gz"

[package.structure]
bin = [ "fzf" ]

[[package]]
url = "https://github.com/junegunn/fzf/archive/refs/tags/0.30.0.tar.gz"
type = "tar.gz"
strip-components = 1
output = [
  '*/bin/fzf-tmux',
  '*/man/man1/fzf-tmux.1',
  '*/man/man1/fzf.1',
  '*/shell/completion.bash',
  '*/shell/key-bindings.bash'
]

[package.structure]
"share/man" = ["man"]
"share/bash-completion/completions" = [ "shell/completion.bash" ]
"share/bash-binding/bindings" = [ "shell/key-bindings.bash" ]

[package.rename]
"share/bash-completion/completions/completion.bash" = "share/bash-completion/completions/fzf.bash"
"share/bash-binding/bindings/key-bindings.bash" = "share/bash-binding/bindings/fzf.bash"

remove = [ "shell", "man" ]
)toml";

  auto table = toml::parse(package);
  std::cout << toml::toml_formatter{table, toml::format_flags::indent_array_elements};
}
