A simple change to SerraBreeze to change the Menu buttons icon to also be a circle.

![](https://raw.githubusercontent.com/JoeBaker/SierraBreeze6Edit/master/Screenshot.png)

Also removes the special case for Konsole, which causes thousands of warning within journalctl.

In order to install the theme and add it to your decorations do the following:

```shell
git clone https://github.com/JoeBaker/SierraBreeze6Edit
cd SierraBreeze6Edit
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release -DKDE_INSTALL_LIBDIR=lib -DBUILD_TESTING=OFF -DKDE_INSTALL_USE_QT_SYS_PATHS=ON
sudo make install
```

To avoid logging out, issue

```shell
kwin_x11 --replace &
```

That is it! Your new decoration theme should appear in
_Settings &rarr; Application Style &rarr; Window Decorations_.

## Acknowledgments:

- The authors of Breeze window decorations Martin Gräßlin and Hugo Pereira Da Costa
- Andrey Orst, the author of Breezemite Aurorae window decoration
  https://github.com/andreyorst/Breezemite
- Chris Holland for his blog about patching Breeze decorations
  https://zren.github.io/projects/2017/07/08/patching-breeze-window-decorations.html
