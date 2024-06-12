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

        number = Text("1969", font_size=150)
        self.play(Write(number))
        self.wait()
        self.play(number.animate.scale(0.8).to_edge(UP))
        self.wait()

        dec_table = MathTable(
            [
                [1, 9, 6, 9],
                ["10^3", "10^2", "10^1", "10^0"],
            ]
        ).scale(1.5)
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
        Text.set_default(font="Open Sans")

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

        zero.move_to(ORIGIN)
        one = Text("1", font_size=150)
        one.shift(LEFT)
        self.play(FadeIn(zero, shift=DOWN))
        self.play(FadeIn(one, shift=DOWN), zero.animate.shift(RIGHT))
        self.wait()

        topow0 = MathTex(f"2^0")
        topow0.shift(DOWN * 1.5 + RIGHT)
        topow1 = MathTex(f"2^1")
        topow1.shift(DOWN * 1.5 + LEFT)

        base2 = Text("Base 2")
        base2.to_edge(UP)

        self.play(Write(base2), FadeIn(topow0, shift=DOWN), FadeIn(topow1, shift=DOWN))
        self.wait()

        formula = MathTex(f"(1 \\times 2^1) + (0 \\times 2^0) = 2")
        formula.shift(DOWN * 2.5)
        self.play(Write(formula))
        self.wait()

        self.play(*[FadeOut(mob) for mob in self.mobjects])
        byte = Text("11111111", font_size=150)
        byte_brace = Brace(byte, DOWN * 1.25)
        byte_text = Text("8 bits = 1 byte").next_to(byte_brace, DOWN)
        self.play(Write(byte))
        self.wait()
        self.play(Create(byte_brace))
        self.play(Write(byte_text))

        byte_table = MathTable(
            [
                [1, 1, 1, 1, 1, 1, 1, 1],
                [
                    "2^7",
                    "2^6",
                    "2^5",
                    "2^4",
                    "2^3",
                    "2^2",
                    "2^1",
                    "2^0",
                ],
            ],
            v_buff=0.5,
            h_buff=0.5,
        ).scale(1.5)
        self.play(Uncreate(byte_brace), Uncreate(byte_text))

        self.play(Transform(byte, byte_table))
        self.wait()
        formula = VGroup(
            MathTex(
                f"(1 \\times 2^7) + (1 \\times 2^6) + (1 \\times 2^5) + (1 \\times 2^4) +"
            ),
            MathTex(
                f"(1 \\times 2^3) + (1 \\times 2^2) + (1 \\times 2^1 ) + (1 \\times 2^0) = 255"
            ),
        ).arrange(DOWN)
        formula.to_edge(DOWN)
        self.play(Write(formula))
        self.wait(2)

        self.play(*[FadeOut(mob) for mob in self.mobjects])

        number = Text("27", font_size=150)
        self.play(Write(number))
        self.wait()
        self.play(number.animate.scale(0.8).to_edge(UP))
        self.wait()

        bin_table = MathTable(
            [
                [1, 1, 0, 1, 1],
                ["2^4", "2^3", "2^2", "2^1", "2^0"],
            ]
        ).scale(1.5)
        self.play(Create(bin_table), run_time=4)
        self.wait()
        formula = MathTex(
            f"(1 \\times 2^4) + (1 \\times 2^3) + (0 \\times 2^2) + (1 \\times 2^1 ) + (1 \\times 2^0) = 27"
        )
        formula.to_edge(DOWN)
        self.play(Write(formula))
        self.wait(2)

        self.play(*[FadeOut(mob) for mob in self.mobjects])


class Hex(Scene):
    def construct(self):
        Text.set_default(font="Open Sans", font_size=150)

        zton = Text("0 - 9")
        self.play(Write(zton))
        self.wait()

        a = Text("A = 10")
        b = Text("B = 11")
        c = Text("C = 12")
        d = Text("D = 13")
        e = Text("E = 14")
        f = Text("F = 15")

        self.play(ReplacementTransform(zton, a))
        self.play(ReplacementTransform(a, b))
        self.play(ReplacementTransform(b, c))
        self.play(ReplacementTransform(c, d))
        self.play(ReplacementTransform(d, e))
        self.play(ReplacementTransform(e, f))
        self.wait()
        self.play(FadeOut(f, shift=DOWN))

        byte = Text("11111111")
        self.play(Write(byte))
        byte_brace = Brace(byte).shift(DOWN * 0.25)
        self.play(Create(byte_brace))
        onebyte = Text("8 bits = 1 byte", font_size=35).next_to(byte_brace, DOWN * 0.25)
        self.play(Write(onebyte))
        self.wait()
        nib_brace = Brace(byte[4:]).shift(DOWN * 0.25)
        onenib = Text("4 bits = 1 nibble", font_size=35).next_to(nib_brace, DOWN * 0.25)
        self.play(
            ReplacementTransform(byte_brace, nib_brace),
            ReplacementTransform(onebyte, onenib),
        )
        self.wait()
        nibble = Text("1111")
        self.play(Uncreate(nib_brace), Uncreate(onenib), run_time=0.5)
        self.play(ReplacementTransform(byte, nibble))
        self.wait()
        self.play(nibble.animate.scale(0.8).to_edge(UP))
        self.wait()
        bin_table = MathTable(
            [
                [1, 1, 1, 1],
                ["2^3", "2^2", "2^1", "2^0"],
            ]
        ).scale(1.5)
        self.play(Create(bin_table), run_time=4)
        self.wait()
        formula = MathTex(
            f"(1 \\times 2^3) + (1 \\times 2^2) + (1 \\times 2^1 ) + (1 \\times 2^0) = 15"
        )
        formula.to_edge(DOWN)
        self.play(Write(formula))
        self.wait(2)

        self.play(Uncreate(bin_table), Uncreate(formula))
        self.play(nibble.animate.scale(1).move_to(ORIGIN))

        byte = Text("11111111")
        self.play(ReplacementTransform(nibble, byte))
        self.wait()
        first_nib_brace = Brace(byte[4:]).shift(DOWN * 0.25)
        first_nib_val_dec = Text("15", font_size=45).next_to(
            first_nib_brace, DOWN * 0.75
        )
        first_nib_val_hex = Text("F", font_size=45).next_to(
            first_nib_brace, DOWN * 0.75
        )
        self.play(Create(first_nib_brace))
        self.play(Write(first_nib_val_dec))
        self.wait()
        self.play(ReplacementTransform(first_nib_val_dec, first_nib_val_hex))
        self.wait()

        second_nib_brace = Brace(byte[0:4]).shift(DOWN * 0.25)
        second_nib_val_dec = Text("15", font_size=45).next_to(
            second_nib_brace, DOWN * 0.5
        )
        second_nib_val_hex = Text("F", font_size=45).next_to(
            second_nib_brace, DOWN * 0.75
        )
        self.play(Create(second_nib_brace))
        self.play(Write(second_nib_val_dec))
        self.wait()
        self.play(ReplacementTransform(second_nib_val_dec, second_nib_val_hex))
        self.wait()

        ff = VGroup(first_nib_val_hex, second_nib_val_hex)
        hex_val = Text("FF")
        self.play(
            Uncreate(byte),
            Uncreate(first_nib_brace),
            Uncreate(second_nib_brace),
        )
        self.play(ReplacementTransform(ff, hex_val))
        self.wait()
        hex_val_notation = Text("0xFF")
        self.play(ReplacementTransform(hex_val, hex_val_notation))
        self.wait()
        equ = Text("0xFF = 255")
        self.play(ReplacementTransform(hex_val_notation, equ))
        self.wait()

        self.play(*[FadeOut(mob) for mob in self.mobjects])
