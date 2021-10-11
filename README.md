# Клонировать и скомпилировать

*Клонировать*

```bash
git clone https://github.com/haxscramper/agat_sem7.git
```

*Скомилировать в консоли*

```bash
cd agat_sem7
qmake
make -j8
```

*Скомилировать в QtCreator* - открыть `agat_sem7.pro`

# Реализовать функционал

- Сделать свою гит ветку - `git checkout -b <название функционала на
  английском>` (например `git checkout -b test_feature`)
- Отредактировать код
- `git add .` для того чтобы добавить изменения в гит
- `git commit -m "<описание изменений>"`
- `git push origin <название созданной ветки>` (например `git push origin
  test_feature`)
