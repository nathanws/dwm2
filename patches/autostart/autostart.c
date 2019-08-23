void
runAutostart(void)
{
  system("cd ~/.config/dwm; ./autostart_blocking.sh");
  system("cd ~/.config/dwm; ./autostart.sh");
}
