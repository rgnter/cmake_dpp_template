#include <dpp/dpp.h>

#include <cstdio>
#include <string>
#include <fstream>
#include <filesystem>

namespace
{

  //! Gets the token from file.
  //! @param path Path to the file containing the token.
  //! @returns Token.
  std::string get_token(const std::filesystem::path& path)
  {
    std::ifstream stream(path);
    if (!stream.is_open())
      throw std::runtime_error("Token file doesn't exist in the working directory");

    std::string token;
    std::getline(stream, token);
    return token;
  }

} // anonymous namespace


int main(int argc, char** argv)
{
  try {
    // Read how to start writing your own bot here:
    // https://dpp.dev/firstbot.html

    std::printf("The working directory: %s\n", argv[0]);

    // Token is fetched from file "token.secret" which should be located
    // in the working directory of the application.
    // The working directory for your application is usually the build folder.
    // To figure out where the build folder is, run the bot once and it will output
    // its working directory thanks to the printf call above.
    dpp::cluster bot(get_token("token.secret"));

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id));
        }
    });

    bot.start(dpp::st_wait);
  } catch(const std::exception& x) {
    std::printf("Exception occured: %s", x.what());
  }
  return 0;
}