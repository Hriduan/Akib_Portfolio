# Build this portfolio on Android with Termux

Install `git`, `clang` and `python` in Termux, then extract this project into Termux's home directory (not shared storage). From the project folder run:

```bash
clang++ -std=c++17 main.cpp -o build_site
./build_site
python tools/check_site.py
```

Open `index.html` in a browser or use `python -m http.server 8080` to preview it locally.

The profile and education copy lives in `about-me.txt`; project descriptions live in each project folder under `projects/`. The shared layout and design live in `ui/`. Replace the supplied portrait or CV only with assets Akib has approved for public use. Review the generated files before deploying; this package does not publish the website.
