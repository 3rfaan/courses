from manim import *


class Title(Scene):
    def construct(self):
        Text.set_default(font="Open Sans")
        title = Text("Data Representation")
        self.play(Write(title))
        self.wait()


class Decimal(Scene):
    def construct(self):
        Text.set_default(font="Open Sans")

        digit = Text("0", font_size=150)
        self.play(FadeIn(digit), shift=DOWN, run_time=0.5)

        for i in range(1, 10):
            self.play(Transform(digit, Text(f"{i}", font_size=150)), run_time=0.1)
            self.wait()

        one = Text("1", font_size=150)
        one.shift(LEFT)
        self.play(Transform(digit, Text("0", font_size=150), font_size=150))
        self.play(FadeIn(one, shift=DOWN), digit.animate.shift(RIGHT))
        self.wait()

        topow0 = MathTex(f"10^0")
        topow0.shift(DOWN * 1.5 + RIGHT)
        topow1 = MathTex(f"10^1")
        topow1.shift(DOWN * 1.5 + LEFT)

        base10 = Text("Base 10")
        base10.to_edge(UP)

        self.play(Write(base10), FadeIn(topow0, shift=DOWN), FadeIn(topow1, shift=DOWN))
        self.wait()

        formula = MathTex(f"(1 \\times 10^1) + (0 \\times 10^0) = 10")
        formula.shift(DOWN * 2.5)
        self.play(Write(formula))
        self.wait()

        self.play(*[FadeOut(mob) for mob in self.mobjects])

        number = Text("1969")
        self.play(Write(number))
        self.wait()
        self.play(number.animate.to_edge(UP))
        self.wait()

        dec_table = MathTable(
            [
                [1, 9, 6, 9],
                ["10^3", "10^2", "10^1", "10^0"],
            ]
        )
        self.play(Create(dec_table), run_time=4)
        self.wait()
        formula = MathTex(
            f"(1 \\times 10^3) + (9 \\times 10^2) + (6 \\times 10^1 ) + (9 \\times 10^0) = 1969"
        )
        formula.to_edge(DOWN)
        self.play(Write(formula))
        self.wait(2)
        self.play(*[FadeOut(mob) for mob in self.mobjects])


class Binary(Scene):
    def construct(self):

        zero = Text("0", font_size=150)
        one = Text("1", font_size=150)

        self.play(FadeIn(zero, shift=DOWN))
        self.wait()
        self.play(zero.animate.shift(2 * LEFT))
        low = Text("LOW", font="Open Sans")
        low.next_to(zero, DOWN * 1.25)
        self.play(Write(low))

        one.shift(2 * RIGHT)
        self.play(FadeIn(one, shift=DOWN))
        high = Text("HIGH", font="Open Sans")
        high.next_to(one, DOWN * 1.25)
        self.play(Write(high))
        self.wait()

        group = VGroup(zero, one, high, low)
        self.play(FadeOut(group))
        self.wait()
