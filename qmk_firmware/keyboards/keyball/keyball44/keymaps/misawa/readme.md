# misawa's Keyball44 keymap.

## Use

Download a hex file from a GitHub release and flash it with [promicro-web-updater](https://sekigon-gonnoc.github.io/promicro-web-updater/index.html). Then you're ready to configure them in [remap](https://remap-keys.app/configure).

Another way is to use `qmk` cli.

```
nix-shell -p qmk
qmk setup --home $(pwd)/__qmk__
ln -s $(pwd)/qmk_firmware/keyboards/keyball __qmk__/keyboards/keyball

qmk compile -j 4 -kb keyball/keyball44 -km misawa
qmk flash -kb keyball/keyball44 -km misawa
```

or

```
$ nix develop
[devshell]$ setup
[devshell]$ compile
[devshell]$ flash
```

## Release

Modify source code, commit, tag it and push.
```sh
git tag keyball44-misawa/vX.Y.Z
git push --tags
```

This will trigger a GitHub workflow, and a GitHub release with the generated hex file will be available soon.
