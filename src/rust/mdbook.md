# サンプルメモ

# 数式

前後にスペースを忘れやすいの気をつける。    
Ubuntu環境下では`\\[` and `\\]`では数式は使えない。代わりに`$$`で囲う。

$$ \mu = \frac{1}{N} \sum_{i=0} x_i $$

\\[
  \frac{\pi}{2} =
  \left( \int_{0}^{\infty} \frac{\sin x}{\sqrt{x}} dx \right)^2 =
  \sum_{k=0}^{\infty} \frac{(2k)!}{2^{2k}(k!)^2} \frac{1}{2k+1} =
  \prod_{k=1}^{\infty} \frac{4k^2}{4k^2 - 1}
\\]

インラインは \\( x \\) で表示

## バグ

mdbook-tocを有効にすると数式が有効にならない。