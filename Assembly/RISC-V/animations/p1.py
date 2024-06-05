from manim import *


class NativeProgram(Scene):
    def construct(self):
        Text.set_default(font="Open Sans")

        title = Text("Native Program")
        binary = Text("", font="FiraCode Nerd Font", font_size=150)
        cpu = Text("", font="FiraCode Nerd Font", font_size=150)
        arrow = Arrow(2 * LEFT, 2 * RIGHT)

        self.play(Write(title))
        self.play(title.animate.to_edge(UP))

        self.play(FadeIn(binary, shift=DOWN))
        self.wait()
        self.play(binary.animate.shift(3 * LEFT))

        self.play(GrowArrow(arrow))
        self.play(Write(cpu.shift(3 * RIGHT)))
        self.wait()

        group = VGroup(title, binary, cpu, arrow)
        self.play(FadeOut(group))
        self.wait()


class Binary(Scene):
    def construct(self):
        zero = Text("0", font_size=150)
        one = Text("1", font_size=150)

        self.play(FadeIn(zero, shift=DOWN))
        self.wait()
        self.play(zero.animate.shift(2 * LEFT))

        one.shift(2 * RIGHT)
        self.play(FadeIn(one, shift=DOWN))
        self.wait()

        group = VGroup(zero, one)
        self.play(FadeOut(group))
        self.wait()


class Components(Scene):
    def construct(self):
        Text.set_default(font="FiraCode Nerd Font", font_size=120)

        ram = Text("")
        ram.move_to([-4, 2, 0])
        ram_bot = ram.get_bottom()
        ram_line = Line(ram_bot, ram_bot + DOWN * 1.1)

        hdd = Text("󰋊")
        hdd.move_to([0, 2, 0])
        hdd_bot = hdd.get_bottom()
        hdd_line = Line(hdd_bot, hdd_bot + DOWN * 1.05)

        screen = SVGMobject("./assets/img/screen.svg", height=2.0, width=2.0)
        screen.set_color(WHITE)
        screen.move_to([4, 2, 0])
        screen_bot = screen.get_bottom()
        screen_line = Line(screen_bot, screen_bot + DOWN * 0.9)

        bus = Rectangle(stroke_color=ORANGE, height=0.5, width=10.0)
        bus_text = Text("Bus", font="Open Sans", font_size=25, color=ORANGE).next_to(
            bus, DOWN, buff=0.2
        )

        cpu = Text("")
        cpu.move_to([-4, -2, 0])
        cpu_top = cpu.get_top()
        cpu_line = Line(cpu_top, cpu_top + UP * 0.9)

        kb = SVGMobject("./assets/img/keyboard.svg", height=2.0, width=2.0)
        kb.set_color(WHITE)
        kb.move_to([4, -2, 0])
        kb_top = kb.get_top()
        kb_line = Line(kb_top, kb_top + UP * 1.25)

        self.play(FadeIn(ram, shift=DOWN))
        self.play(FadeIn(cpu, shift=DOWN))
        self.play(FadeIn(hdd, shift=DOWN))
        self.play(FadeIn(screen, shift=DOWN))
        self.play(FadeIn(kb, shift=DOWN))

        self.wait()
        self.play(
            Create(bus),
            Write(bus_text),
            Create(ram_line),
            Create(cpu_line),
            Create(hdd_line),
            Create(screen_line),
            Create(kb_line),
        )
        self.wait()
        group = VGroup(
            ram,
            hdd,
            screen,
            cpu,
            kb,
            bus,
            bus_text,
            ram_line,
            cpu_line,
            hdd_line,
            screen_line,
            kb_line,
        )
        self.play(FadeOut(group))
        self.wait()


class Memory(Scene):
    def construct(self):
        Text.set_default(font="FiraCode Nerd Font", font_size=25)

        ram = Text("", font_size=120)

        self.play(FadeIn(ram, shift=DOWN))

        memory = Table(
            [
                ["00110110"],
                ["00000000"],
                ["00001000"],
                ["10000000"],
                ["11110000"],
                ["11111111"],
                ["00001111"],
                ["11100001"],
            ],
            include_outer_lines=True,
        )
        memory.scale(0.75)

        memory_hex = Table(
            [
                ["0x36"],
                ["0x00"],
                ["0x08"],
                ["0x80"],
                ["0xF0"],
                ["0xFF"],
                ["0x0F"],
                ["0xE1"],
            ],
            include_outer_lines=True,
        )
        memory_hex.scale(0.75)

        addresses = VGroup(*[Integer(i) for i in range(0, 8)])
        addresses.scale(0.75)
        addresses.arrange(direction=DOWN, buff=0.55)
        addresses.next_to(memory, LEFT)

        addresses_brace = BraceBetweenPoints([-1.5, 3, 0], [-1.5, -3, 0])
        addresses_text = Text("Addresses", font="Open Sans", font_size=15)
        addresses_text.move_to([-2.8, 0, 0])

        byte = DoubleArrow(start=LEFT * 1.35, end=RIGHT * 1.35, tip_length=0.1)
        byte_text = Text("1 byte", font="Open Sans", font_size=15)
        byte.to_edge(UP)
        byte_text.next_to(byte, UP * 0.5)

        byte_adjusted = DoubleArrow(start=LEFT, end=RIGHT, tip_length=0.1)
        byte_adjusted.to_edge(UP)

        self.play(ReplacementTransform(ram, memory))
        self.play(Create(addresses))
        self.play(GrowFromCenter(addresses_brace))
        self.play(Write(addresses_text))
        self.play(GrowFromCenter(byte))
        self.play(Write(byte_text))
        self.wait()
        self.play(
            ReplacementTransform(memory, memory_hex),
            ReplacementTransform(byte, byte_adjusted),
        )
        self.wait(3)
