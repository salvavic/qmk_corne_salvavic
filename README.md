# Layout de Salvador

## Comando compilacion
- Compilar y flash:
  `qmk flash -kb crkbd -km salvavic`
- Solo compilar:
  `qmk compile -kb kprepublic/bm40hsrgb -km salvavic`

## Comandos para añadir al repo e inicializar
`git submodule add https://github.com/salvavic/qmk_corne_salvavic.git keyboards/crkbd/keymaps/salvavic`

`git submodule init`

`git submodule update`

`qmk setup`

## Keymap
