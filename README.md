# cg22-project-horosho


## Зависимости

### Arch-based GNU/Linux-дистрибутивы
- qt6-base
- libdeflate
```
sudo pacman -S qt6-base libdeflate
```
Или предпочитаемый pacman-wrapper, т.к. yay, paru, aura и т.п.
### Windows (нужен Python и pip.)
##### Qt
```
pip install aqtinstaller
aqt install-qt windows desktop 6.4.0 win64_msvc2019_64 --archives qtbase
```
Также можно установить много-много пакетов через официальный установщик

#### Libdefalte

Придется скачать самостоятельно, вероятно, можно воспользоваться утилитами типа conan, но в данном README инструкции и 
конфигураций не прилагается.

## Сборка

Сначала склонировать репозиторий

```
git clone https://github.com/IS-CG/cg22-project-horosho.git
```

Можно использовать аргумент --depth, чтобы ускорить загрузку и не скачивать всю историю

```
git clone --depth 1 https://github.com/IS-CG/cg22-project-horosho.git
```

Непосредственно сборка

```
mkdir build
cd build
cmake ..
ninja
```
### Сборка на Windows
#### Qt
1. Необходимо установить в CMakeLists.txt переменную CMAKE_PREFIX_PATH с путем до /lib/cmake в папке, где установлен Qt
2. Также для запуска нужно установить переменную окружения QT_PLUGIN_PATH с путем до папки /plugins в корневой папке Qt
3. Добавить в $PATH путь до папки /bin в корневой папке Qt либо просто скопировать необходимые .dll из той же папки в место, где находится исполняемый файл

#### Libdeflate

В CMakeLists.txt уже прописаны необходимые выражения для подключения этой библиотеки. Вам необходимо определить
заданные переменные окружения перед сборкой либо заменить их путями к необходимым файлами прямо в файле конфигурации.

## Запуск

### Linux

```
./horoshoeditor
```

### Windows

```
.\horoshoeditor.exe
```