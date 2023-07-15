from fpdf import FPDF


class PDF(FPDF):
    def header(self):
        # Rendering logo
        self.image('shirtificate.png', 10, 50, 190)
        # Setting font
        self.set_font('helvetica', 'B', 50)
        # Printing title
        self.cell(0, 20, 'CS50 shirtificate', align="C")
        # Performing a line break
        self.ln(20)

    def footer(self):
        # Setting font
        self.set_font('helvetica', 'I', 35)
        # Setting font's colour
        self.set_text_color(255, 255, 255)
        # Printing name
        self.cell(185, 150, f'{name} took CS50', align="C")


# Instantiation of inherited class
name = input('Name please: ')
pdf = PDF()
pdf.add_page()
pdf.output('shirtificate.pdf')