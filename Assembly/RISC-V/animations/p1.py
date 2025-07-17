from manim import *


class Title(Scene):
    def construct(self):
        Text.set_default(font="Open Sans")
        title = Text("Computer Components")
        self.play(Write(title))
        self.wait()


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
        kb_line = Line(kb_top, kb_top + UP * 1.05)

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
                ["0xE2"],
                ["0xE4"],
                ["0xE6"],
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
        self.wait()

        self.play(*[FadeOut(mob) for mob in self.mobjects])
        self.wait()


class CPUInstruction(Scene):
    def construct(self):
        Text.set_default(font="FiraCode Nerd Font", font_size=15)

        # self.add(NumberPlane())

        memory = Table(
            [
                ["00010011"],
                ["00000101"],
                ["00010101"],
                ["00000000"],
                ["10010011"],
                ["10000101"],
                ["11110101"],
                ["11111111"],
                ["11100011"],
                ["00001100"],
                ["10110101"],
                ["11111110"],
            ],
            v_buff=0.35,
            h_buff=0.8,
            include_outer_lines=True,
        )

        code = """
        loop:
            addi a0, a0, 1
            addi a1, a1, -1
            beq  a0, a1, loop
        """

        rendered_code = Code(
            code=code, tab_width=4, language="asm", font="FiraCode Nerd Font"
        )
        memory.shift(RIGHT * 4)

        self.play(Create(rendered_code))
        self.wait()
        self.play(rendered_code.animate.to_edge(DL))

        self.play(Create(memory), run_time=2)
        self.wait()

        first_inst = MarkupText(
            f'<span fgcolor="{RED}">addi</span> a0, a0, 1',
            font="FiraCode Nerd Font",
            font_size=15,
        )
        first_inst_brace = BraceBetweenPoints([3, 3, 0], [3, 1, 0])

        first_inst.move_to([1.2, 2, 0])
        self.play(
            Write(first_inst),
            GrowFromCenter(first_inst_brace),
        )
        self.wait()

        second_inst = MarkupText(
            f'<span fgcolor="{RED}">addi</span> a1, a1, -1',
            font="FiraCode Nerd Font",
            font_size=15,
        )
        second_inst_brace = BraceBetweenPoints([3, 1, 0], [3, -1, 0])

        second_inst.move_to([1.2, 0, 0])
        self.play(
            Write(second_inst),
            GrowFromCenter(second_inst_brace),
        )
        self.wait()

        third_inst = MarkupText(
            f'<span fgcolor="{RED}">beq</span>  a0, a1, loop',
            font="FiraCode Nerd Font",
            font_size=15,
        )
        third_inst_brace = BraceBetweenPoints([3, -1, 0], [3, -3, 0])

        third_inst.move_to([1.2, -2, 0])
        self.play(
            Write(third_inst),
            GrowFromCenter(third_inst_brace),
        )
        self.wait()

        self.play(*[FadeOut(mob) for mob in self.mobjects])
        self.wait()


class ExecutionCycle(Scene):
    def construct(self):
        Text.set_default(font="FiraCode Nerd Font", font_size=15)

        binary = Text("", font="FiraCode Nerd Font", font_size=150)

        self.play(FadeIn(binary, shift=DOWN))
        self.wait()

        memory = Table(
            [
                ["00010011"],
                ["00000101"],
                ["00010101"],
                ["00000000"],
                ["10010011"],
                ["10000101"],
                ["11110101"],
                ["11111111"],
                ["11100011"],
                ["00001100"],
                ["10110101"],
                ["11111110"],
            ],
            v_buff=0.35,
            h_buff=0.8,
            include_outer_lines=True,
        )
        memory.shift(RIGHT * 4)

        self.play(ReplacementTransform(binary, memory))
        self.wait()

        pc = Arrow(start=LEFT, end=RIGHT, tip_length=0.1)
        pc_text = Text("PC", font="Open Sans")
        pc.move_to([2, 2.75, 0])
        always_redraw(lambda: pc_text.next_to(pc, LEFT))

        self.play(GrowArrow(pc), Write(pc_text))
        self.wait()

        cpu_icon = Text("", font="FiraCode Nerd Font", font_size=150)
        cpu_icon.move_to(LEFT * 4)
        cpu = Rectangle(width=5.0, height=3.0)
        cpu.move_to(LEFT * 4)

        self.play(FadeIn(cpu_icon, shift=DOWN))
        self.wait()
        self.play(ReplacementTransform(cpu_icon, cpu))
        self.wait()

        word_brace = BraceBetweenPoints([5, 3, 0], [5, 1, 0], direction=RIGHT)
        word_text = Text("word", font="Open Sans")
        always_redraw(lambda: word_text.next_to(word_brace, RIGHT))
        self.play(GrowFromCenter(word_brace), Write(word_text))
        self.wait()

        memory_copy = memory.copy()
        self.add(memory_copy)
        entry = memory_copy.get_entries_without_labels()

        four_bytes = entry[0:4]
        next_four = entry[4:8]

        fetch = Text("Fetch", font="Open Sans", font_size=25)
        fetch.move_to(cpu.get_edge_center(UP) + UP * 0.5)
        self.play(Write(fetch))
        self.wait()

        self.play(four_bytes.animate.move_to(cpu.get_center()))
        self.wait()

        self.play(pc.animate.move_to([2, 0.75, 0]))
        self.wait()

        decode = Text("Decode", font="Open Sans", font_size=25)
        decode.move_to(cpu.get_edge_center(UP) + UP * 0.5)

        inst = MarkupText(
            f'<span fgcolor="{RED}">addi</span> a0, a0, 1',
            font="FiraCode Nerd Font",
            font_size=15,
        )
        inst.move_to(cpu.get_center())
        self.play(
            ReplacementTransform(fetch, decode), ReplacementTransform(four_bytes, inst)
        )
        self.wait()

        execute = Text("Execute", font="Open Sans", font_size=25)
        execute.move_to(cpu.get_edge_center(UP) + UP * 0.5)

        self.play(ReplacementTransform(decode, execute), FadeOut(inst))

        new_word_brace = BraceBetweenPoints([5, 1, 0], [5, -1, 0], direction=RIGHT)
        self.play(ReplacementTransform(word_brace, new_word_brace))
        self.wait()

        fetch = Text("Fetch", font="Open Sans", font_size=25)
        fetch.move_to(cpu.get_edge_center(UP) + UP * 0.5)
        inst_two = MarkupText(
            f'<span fgcolor="{RED}">addi</span> a1, a1, -1',
            font="FiraCode Nerd Font",
            font_size=15,
        )
        inst_two.move_to(cpu.get_center())
        self.play(
            ReplacementTransform(execute, fetch),
            next_four.animate.move_to(cpu.get_center()),
        )
        self.wait()

        self.play(FadeOut(new_word_brace, word_text))

        self.play(pc.animate.move_to([2, -1.25, 0]))
        self.wait()

        decode = Text("Decode", font="Open Sans", font_size=25)
        decode.move_to(cpu.get_edge_center(UP) + UP * 0.5)
        self.play(
            ReplacementTransform(fetch, decode),
            ReplacementTransform(next_four, inst_two),
        )
        self.wait()

        execute = Text("Execute", font="Open Sans", font_size=25)
        execute.move_to(cpu.get_edge_center(UP) + UP * 0.5)
        self.play(ReplacementTransform(decode, execute), FadeOut(inst_two))
        self.wait()

        self.play(*[FadeOut(mob) for mob in self.mobjects])
        self.wait()


class CPU(Scene):
    def construct(self):
        Text.set_default(font="Open Sans", font_size=25)

        cpu = Rectangle(width=10, height=6)
        regs = Table(
            [
                ["x0", "x1", "x2", "x3", "x4"],
                ["x5", "x6", "x7", "x8", "x9"],
                ["x10", "x11", "x12", "x13", "x14"],
                ["x15", "x16", "x17", "x18", "..."],
            ],
            v_buff=0.3,
            h_buff=0.3,
            include_outer_lines=True,
        )
        regs.align_to(cpu, UL)
        regs.shift(RIGHT * 0.25 + DOWN * 0.25)

        self.play(Create(cpu))
        self.wait()
        self.play(Create(regs))
        self.wait()

        alu = SVGMobject("./assets/img/alu.svg")
        alu.set_color = WHITE

        alu.align_to(cpu, UR)
        alu.shift(LEFT * 0.25 + DOWN * 0.25)
        self.play(Create(alu))
        self.wait()

        cu = Rectangle(width=3, height=2)
        cu_text = Text("Control Unit")
        cu.align_to(cpu, DL)
        cu.shift(RIGHT * 0.25 + UP * 0.25)
        cu_text.move_to(cu.get_center())
        self.play(Create(cu), Write(cu_text))
        self.wait()

        pc_txt = Text("Programm Counter")
        io_txt = Text("Input / Output")

        pc_rec = SurroundingRectangle(pc_txt, color=WHITE)
        io_rec = SurroundingRectangle(io_txt, color=WHITE)

        pcio = VGroup(VGroup(pc_txt, pc_rec), VGroup(io_txt, io_rec))
        pcio.arrange(DOWN)
        pcio.align_to(cpu, DR)
        pcio.shift(LEFT * 0.25 + UP * 0.25)

        self.play(Create(pcio))
        self.wait()
